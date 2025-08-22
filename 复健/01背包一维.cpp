#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 3405;
const int maxm = 12880;
int dp[maxm];
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
        for (re int j = m; j >= a[i].weight; --j)
        {
            dp[j] = max(dp[j - a[i].weight] + a[i].value, dp[j]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
