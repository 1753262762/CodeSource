#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 1e5 + 100;
const int logn = 21;

int ST[Maxn][logn], Log[Maxn];
int n, m;
void solve_st()
{
    Log[2] = 1;
    for (re int i = 3; i < Maxn; ++i)
    {
        Log[i] = Log[i >> 1] + 1;
    }
    for (re int j = 1; j <= logn; ++j)
    {
        for (re int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }
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
    n = read(), m = read();
    for (re int i = 1; i <= n; ++i)
    {
        ST[i][0] = read();
    }
    solve_st();
    for (re int i = 1; i <= m; ++i)
    {
        re int l = read(), r = read();
        re int deep = Log[r - l + 1];
        printf("%d\n", max(ST[l][deep], ST[r - (1 << deep) + 1][deep]));
    }
    return 0;
}