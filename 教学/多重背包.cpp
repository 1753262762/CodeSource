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
        for (re int j = a[i].weight; j <= Weight; ++j)
        {
            dp[j] = max(dp[j - a[i].weight] + a[i].value, dp[j]);
        }
    }
    cout << dp[Weight] << endl;
    return 0;
}