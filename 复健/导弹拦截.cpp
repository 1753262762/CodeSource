#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 1e5 + 10;

int n, a[maxn];
int dp[maxn];
int len1[maxn];
int dp2[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in", "r", stdin);
#endif
    int tmp;
    while (cin >> tmp)
    {
        a[++n] = tmp;
    }
    dp[1] = 1;
    dp2[1] = 1;
    for (re int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        // int l = 1, r = i - 1;
        // // 找a[j]>a[i]
        // while (l < r)
        // {
        //     int mid = (l + r) / 2;
        //     cout << l << ' ' << r << ' ' << len1[mid] << endl;
        //     if (len1[mid] > a[i])
        //     {
        //         l = mid;
        //     }
        //     else
        //     {
        //         r = mid + 1;
        //     }
        // }
        // dp[i] = l + 1;
        // len1[l + 1] = max(a[i], len1[l + 1]);
        for (re int j = 1; j < i; ++j)
        {
            if (a[j] >= a[i])
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
            if (a[j] < a[i])
            {
                dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for (re int i = 1; i <= n; ++i)
    {
        ans1 = max(ans1, dp[i]);
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    for (re int i = 1; i <= n; ++i)
    {
        ans2 = max(ans2, dp2[i]);
        // cout << dp2[i] << ' ';
    }
    // cout << endl;
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}