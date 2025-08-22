#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 1e6 + 10;
const int mod = 998244353;

int Tree[maxn], n;

static inline int lowbit(int x)
{
    return x & -x;
}
static inline int sum(int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += Tree[pos];
        pos -= lowbit(pos);
    }
    return res;
}
static inline int query(int l, int r)
{
    return sum(r) - sum(l - 1);
}
static inline void add(int pos, int x)
{
    while (pos <= n)
    {
        Tree[pos] += x;
        pos += lowbit(pos);
    }
}
long long f[maxn];
long long ans = 0;
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
    n = read();
    f[0] = 1;
    for (re int i = 1; i <= n; ++i)
    {
        f[i] = (f[i - 1] * i) % mod;
    }
    for (re int i = 1; i <= n; ++i)
    {
        add(i, 1);
    }
    for (re int i = 1; i <= n; ++i)
    {
        re int x;
        x = read();
        add(x, -1);
        ans = (ans + (long long)(sum(x) * f[n - i]) % mod) % mod;
    }
    cout << ans + 1 << endl;
    return 0;
}