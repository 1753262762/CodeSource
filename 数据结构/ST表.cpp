#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 1e5 + 10;

int n, m;
int ST[Maxn][21], Logn[Maxn];
void solve()
{
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < Maxn; ++i)
    {
        Logn[i] = Logn[i / 2] + 1;
    }
    for (re int j = 1; j <= 21; ++j)
    {
        for (re int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int RMQ(int l, int r)
{
    int tmp = Logn[r - l + 1];
    return max(ST[l][tmp], ST[r - (1 << tmp) + 1][tmp]);
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
    n = read(), m = read();
    for (re int i = 1; i <= n; ++i)
    {
        ST[i][0] = read();
    }
    solve();
    for (re int i = 1; i <= m; ++i)
    {
        re int l = read(), r = read();
        cout << RMQ(l, r) << endl;
    }
    return 0;
}