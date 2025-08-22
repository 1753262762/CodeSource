/*
2313
4281
3278
*/
#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 1e6 + 100;

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
    re int lson = (id << 1), rson = lson | 1;
    build(l, l + ((r - l) >> 1), lson);
    build(l + ((r - l) >> 1) + 1, r, rson);
    Tree[id] = (node){l, r, r - l + 1, Tree[lson].sum + Tree[rson].sum};
    return;
}
void add(int id)
{
    re int lson = (id << 1), rson = lson | 1;
    Tree[lson].sum += Tree[lson].len * Tree[id].lazy, Tree[rson].sum += Tree[rson].len * Tree[id].lazy;
    Tree[lson].lazy += Tree[id].lazy, Tree[rson].lazy += Tree[id].lazy;
    Tree[id].lazy = 0;
}
long long query_sum(int l, int r, int id)
{
    if (l <= Tree[id].l and r >= Tree[id].r)
        return Tree[id].sum;
    if (Tree[id].lazy)
        add(id);
    re int lson = (id << 1), rson = lson | 1;
    if (Tree[lson].r < l)
        return query_sum(l, r, rson);
    else if (Tree[rson].l > r)
        return query_sum(l, r, lson);
    return query_sum(l, r, lson) + query_sum(l, r, rson);
}
void updata(int l, int r, int x, int id)
{
    if (l <= Tree[id].l and r >= Tree[id].r)
    {
        Tree[id].sum += Tree[id].len * x;
        Tree[id].lazy += x;
        return;
    }
    if (Tree[id].lazy)
        add(id);
    re int lson = (id << 1), rson = lson | 1;
    if (Tree[lson].r < l)
        updata(l, r, x, rson);
    else if (Tree[rson].l > r)
        updata(l, r, x, lson);
    else
        updata(l, r, x, lson), updata(l, r, x, rson);
    Tree[id].sum = Tree[lson].sum + Tree[rson].sum;
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
    // freopen("a.in", "r", stdin);
    int n = read(), m = read();
    for (re int i = 1; i <= n; ++i)
    {
        x[i] = read();
    }
    build(1, n, 1);
    for (re int i = 1; i <= m; ++i)
    {
        int ope = read();
        if (ope == 1)
        {
            int l = read(), r = read(), sum = read();
            updata(l, r, sum, 1);
        }
        else if (ope == 2)
        {
            int l = read(), r = read();
            cout << query_sum(l, r, 1) << endl;
        }
    }
    return 0;
}