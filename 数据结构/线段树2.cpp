/*
2313
4281
3278
*/
#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 1e6 + 100;

int mod;
struct node
{
    int l, r, len;
    long long sum;
    long long lazy, mul;
} Tree[Maxn << 2];
int x[Maxn];
static inline void updata(int id)
{
    Tree[id].sum = (Tree[id << 1].sum + Tree[(id << 1) | 1].sum) % mod;
    return;
}
static inline void add(int id)
{
    re int lson = (id << 1), rson = lson | 1;
    Tree[lson].sum = (Tree[lson].sum * Tree[id].mul + Tree[lson].len * Tree[id].lazy) % mod;
    Tree[rson].sum = (Tree[rson].sum * Tree[id].mul + Tree[rson].len * Tree[id].lazy) % mod;
    Tree[lson].mul = (Tree[lson].mul * Tree[id].mul) % mod;
    Tree[rson].mul = (Tree[rson].mul * Tree[id].mul) % mod;
    Tree[lson].lazy = (Tree[lson].lazy * Tree[id].mul + Tree[id].lazy) % mod;
    Tree[rson].lazy = (Tree[rson].lazy * Tree[id].mul + Tree[id].lazy) % mod;
    Tree[id].lazy = 0;
    Tree[id].mul = 1;
    return;
}
void build(int l, int r, int id)
{
    if (l == r)
    {
        Tree[id] = (node){l, r, 1, x[l] % mod, 0, 1};
        return;
    }
    re int lson = (id << 1), rson = lson | 1;
    build(l, l + ((r - l) >> 1), lson);
    build(l + ((r - l) >> 1) + 1, r, rson);
    Tree[id] = (node){l, r, r - l + 1, (Tree[lson].sum + Tree[rson].sum) % mod, 0, 1};
    return;
}
long long query_sum(int l, int r, int id)
{
    if (l <= Tree[id].l and r >= Tree[id].r)
        return Tree[id].sum % mod;
    add(id);
    re int lson = (id << 1), rson = lson | 1;
    if (Tree[lson].r < l)
        return query_sum(l, r, rson) % mod;
    else if (Tree[rson].l > r)
        return query_sum(l, r, lson) % mod;
    return (query_sum(l, r, lson) + query_sum(l, r, rson)) % mod;
}
void updata_add(int l, int r, int x, int id)
{
    if (l <= Tree[id].l and r >= Tree[id].r)
    {
        Tree[id].sum = (Tree[id].sum + Tree[id].len * x) % mod;
        Tree[id].lazy = (Tree[id].lazy + x) % mod;
        return;
    }
    add(id);
    re int lson = (id << 1), rson = lson | 1;
    if (Tree[lson].r < l)
        updata_add(l, r, x, rson);
    else if (Tree[rson].l > r)
        updata_add(l, r, x, lson);
    else
        updata_add(l, r, x, lson), updata_add(l, r, x, rson);
    updata(id);
    return;
}
void updata_mul(int l, int r, int x, int id)
{
    if (l <= Tree[id].l and r >= Tree[id].r)
    {
        Tree[id].lazy = (Tree[id].lazy * x) % mod;
        Tree[id].mul = (Tree[id].mul * x) % mod;
        Tree[id].sum = (Tree[id].sum * x) % mod;
        return;
    }
    add(id);
    re int lson = (id << 1), rson = lson | 1;
    if (Tree[lson].r < l)
        updata_mul(l, r, x, rson);
    else if (Tree[rson].l > r)
        updata_mul(l, r, x, lson);
    else
        updata_mul(l, r, x, lson), updata_mul(l, r, x, rson);
    updata(id);
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
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n = read(), m = read();
    mod = read();
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
            updata_mul(l, r, sum, 1);
        }
        else if (ope == 2)
        {
            int l = read(), r = read(), sum = read();
            updata_add(l, r, sum, 1);
        }
        else if (ope == 3)
        {
            int l = read(), r = read();
            cout << query_sum(l, r, 1) << endl;
        }
    }
    return 0;
}