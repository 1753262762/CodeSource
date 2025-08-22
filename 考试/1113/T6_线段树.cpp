/*
2313
4281
3278
*/
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1e6 + 100;
int flag = 0;
struct node
{
    int l, r, len;
    long long sum;
    int lazy;
    void output()
    {
        cout << l << ' ' << r << ' ' << sum << endl;
    }
} Tree[Maxn];
int x[Maxn];
void build(int l, int r, int id)
{
    if (l == r)
    {
        Tree[id] = (node){l, r, 1, x[l]};
        return;
    }
    int lson = (id << 1), rson = lson | 1;
    build(l, l + ((r - l) >> 1), lson);
    build(l + ((r - l) >> 1) + 1, r, rson);
    Tree[id] = (node){l, r, r - l + 1, Tree[lson].sum + Tree[rson].sum};
    return;
}
void add(int id)
{
    int lson = (id << 1), rson = lson | 1;
    Tree[lson].sum += Tree[lson].len * Tree[id].lazy, Tree[rson].sum += Tree[rson].len * Tree[id].lazy;
    Tree[lson].lazy += Tree[id].lazy, Tree[rson].lazy += Tree[id].lazy;
    Tree[id].lazy = 0;
}
void updata(int l, int r, int x, int id)
{
    if (l <= Tree[id].l and r >= Tree[id].r)
    {
        Tree[id].sum += Tree[id].len * x;
        Tree[id].lazy += x;
        if (Tree[id].sum < 0)
            flag = 1;
        return;
    }
    if (Tree[id].lazy)
        add(id);
    int lson = (id << 1), rson = lson | 1;
    if (Tree[lson].r < l)
        updata(l, r, x, rson);
    else if (Tree[rson].l > r)
        updata(l, r, x, lson);
    else
        updata(l, r, x, lson), updata(l, r, x, rson);
    Tree[id].sum = Tree[lson].sum + Tree[rson].sum;
    if (Tree[id].sum < 0)
        flag = 1;
    return;
}

inline int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
    {
        x[i] = read();
    }
    build(1, n, 1);
    for (int i = 1; i <= m; ++i)
    {
        int sum = read(), l = read(), r = read();
        updata(l, r, sum, 1);
        if (flag == 1)
        {
            cout << -1 << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}