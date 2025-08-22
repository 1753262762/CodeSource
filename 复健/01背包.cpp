#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 3405;
const int maxm = 12880;
int dp[maxn][maxm];
struct goods
{
    int weight, value;
} a[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i].weight >> a[i].value;
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 0; j <= m; ++j)
        {
            if (j - a[i].weight >= 0)
                dp[i][j] = max(dp[i - 1][j - a[i].weight] + a[i].value, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
