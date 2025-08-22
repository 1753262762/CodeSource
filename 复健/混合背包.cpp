#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 10000 + 5;
const int maxm = 1000 + 10;
struct goods
{
    int weight, value, num;
} x[maxn];
int dp[maxm];
int main()
{
    int hour1, min1, hour2, min2;
    char ss;
    cin >> hour1 >> ss >> min1 >> hour2 >> ss >> min2;
    int n, m;
    cin >> n;
    m = (hour2 - hour1) * 60 + (min2 - min1);
    for (re int i = 1; i <= n; ++i)
    {
        cin >> x[i].weight >> x[i].value >> x[i].num;
    }
    for (re int i = 1; i <= n; ++i)
    {
        if (x[i].num != 0)
        {
            for (re int j = m; j >= x[i].weight; --j)
            {
                for (re int k = 1; k * x[i].weight <= j and k <= x[i].num; ++k)
                {
                    dp[j] = max(dp[j - x[i].weight * k] + x[i].value * k, dp[j]);
                }
            }
        }
        else
        {
            for (re int j = x[i].weight; j <= m; ++j)
            {
                dp[j] = max(dp[j - x[i].weight] + x[i].value, dp[j]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}