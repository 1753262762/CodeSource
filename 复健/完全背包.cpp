#include <bits/stdc++.h>
using namespace std;
#define re register
const int maxn = 1e4 + 5;
const int maxm = 1e7 + 5;
struct goods
{
    int value, weight;
} x[maxn];
long long dp[maxm];
int main()
{
    int n, m;
    cin >> m >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> x[i].weight >> x[i].value;
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = x[i].weight; j <= m; ++j)
        {
            dp[j] = max(dp[j], dp[j - x[i].weight] + x[i].value);
        }
    }
    cout << dp[m] << endl;
    return 0;
}