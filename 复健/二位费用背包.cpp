#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
const int maxm = 200 + 5;
const int maxt = 200 + 5;
#define re register
struct goods
{
    int weight, time;
} x[maxn];
int dp[maxm][maxt];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> x[i].weight >> x[i].time;
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = m; j >= x[i].weight; --j)
        {
            for (re int k = t; k >= x[i].time; --k)
            {
                dp[j][k] = max(dp[j - x[i].weight][k - x[i].time] + 1, dp[j][k]);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}