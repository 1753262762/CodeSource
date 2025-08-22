#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2;
const int maxw = 5e5;
#define re register

struct node
{
    int value, weight;
} a[maxn];

int dp[maxw];
int main()
{
    int n, Weight;
    cin >> n >> Weight;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i].weight >> a[i].value;
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = Weight; j >= a[i].weight; --j)
        {
            // dp[i][j - a[i].weight] +a[i].value 1
            // dp[i][j] 0
            dp[j] = max(dp[j - a[i].weight] + a[i].value, dp[j]);
            // 状态转移方程
        }
    }
    cout << dp[Weight] << endl;
    return 0;
}