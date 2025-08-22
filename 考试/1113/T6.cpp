#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

struct node
{
    int lson, rson, val, lazy;
} Tree[maxn << 2];

int n, m;
bool flag = 1;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void build_tree(int id, int l, int r)
{
    Tree[id].lson = l;
    Tree[id].rson = r;
    Tree[id].lazy = 0;
    if (l == r)
    {
        Tree[id].val = read();
        return;
    }
    else
    {
        int mid = (l + r) >> 1;
        build_tree(id << 1, l, mid);
        build_tree(id << 1 | 1, mid + 1, r);
        Tree[id].val = min(Tree[id << 1].val, Tree[id << 1 | 1].val);
        return;
    }
}

void pushdown(int id)
{
    if (Tree[id].lson == Tree[id].rson || Tree[id].lazy == 0)
        return;
    Tree[id << 1].lazy += Tree[id].lazy;
    Tree[id << 1 | 1].lazy += Tree[id].lazy;
    Tree[id << 1].val -= Tree[id].lazy;
    Tree[id << 1 | 1].val -= Tree[id].lazy;
    Tree[id].lazy = 0;
    Tree[id].val = min(Tree[id << 1].val, Tree[id << 1 | 1].val);
    return;
}

void modify(int id, int l, int r, int d)
{
    pushdown(id);
    if (Tree[id].lson == l && Tree[id].rson == r)
    {
        Tree[id].lazy += d;
        Tree[id].val -= d;
        if (Tree[id].val < 0)
            flag = 0;
        return;
    }
    else
    {
        int mid = (Tree[id].lson + Tree[id].rson) >> 1;
        if (r <= mid)
            modify(id << 1, l, r, d);
        else if (l > mid)
            modify(id << 1 | 1, l, r, d);
        else
        {
            modify(id << 1, l, mid, d);
            modify(id << 1 | 1, mid + 1, r, d);
        }
        Tree[id].val = min(Tree[id << 1].val, Tree[id << 1 | 1].val);
        return;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    build_tree(1, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        int d = read(), s = read(), Tree = read();
        modify(1, s, Tree, d);
        if (!flag)
        {
            cout << -1 << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}