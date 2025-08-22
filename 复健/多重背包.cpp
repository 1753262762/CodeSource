#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 100 + 5;
const int maxm = 4e4 + 5;
const int maxk = 1e5;
struct goods
{
    int weight, value;
} x[maxk];
int cnt = 0;
int dp[maxm];
int main()
{
    int n, m;
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        int value, weight, m;
        cin >> value >> weight >> m;
        int k = 1;
        while (k < m)
        {
            m -= k;
            x[++cnt].value = value * k;
            x[cnt].weight = weight * k;
            k *= 2;
        }
        x[++cnt].value = value * m;
        x[cnt].weight = weight * m;
    }
    for (re int i = 1; i <= cnt; ++i)
    {
        for (re int j = m; j >= x[i].weight; --j)
        {
            dp[j] = max(dp[j - x[i].weight] + x[i].value, dp[j]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}