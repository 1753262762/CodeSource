#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
const int maxw = 1e7 + 10;
#define re register

struct node
{
    int value, weight;
} a[maxn];

int dp[maxw];
int main()
{
    int n, Weight;
    cin >> Weight >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i].weight >> a[i].value;
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int k = 1; k * a[i].weight <= Weight; ++k)
        {
            for (re int j = Weight; j >= k * a[i].weight; --j)
            {
                dp[j] = max(dp[j - a[i].weight * k] + a[i].value * k, dp[j]);
            }
        }
    }
    // for (re int i = 1; i <= n; ++i)
    // {
    //     for (re int j = Weight; j >= a[i].weight; --j)
    //     {
    //         dp[j] = max(dp[j - a[i].weight] + a[i].value, dp[j]);
    //     }
    // }
    cout << dp[Weight] << endl;
    return 0;
}