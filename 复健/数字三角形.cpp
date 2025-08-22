#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
#define re register
int dp[maxn][maxn];
int main()
{
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= i; ++j)
        {
            cin >> dp[i][j];
            dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);
        }
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}