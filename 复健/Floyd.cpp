#include <bits/stdc++.h>
using namespace std;

#define re register
const int Max_n = 100 + 5;
const int INF = 0x3f3f3f3f;

int dp[Max_n][Max_n];

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
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }
    for (re int i = 1; i <= m; ++i)
    {
        int From = read(), To = read(), Ver = read();
        if (Ver < dp[From][To])
        {
            dp[From][To] = Ver;
            dp[To][From] = Ver;
        }
    }
    for (re int k = 1; k <= n; ++k)
    {
        for (re int i = 1; i <= n; ++i)
        {
            for (re int j = 1; j <= n; ++j)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}