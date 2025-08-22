#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 100;

int a[maxn];
int dp[maxn];
int dp2[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (re int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (re int j = 1; j < i; ++j)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        dp2[i] = 1;
        for (re int j = 1; j < i; ++j)
        {
            if (a[j] > a[i])
            {
                dp2[i] = max(dp2[i], max(dp2[j], dp[j]) + 1);
            }
        }
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        ans = max(ans, max(dp[i], dp2[i]));
    }
    cout << n - ans << endl;
    return 0;
}