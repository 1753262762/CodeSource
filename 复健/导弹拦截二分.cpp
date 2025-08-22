#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 1e5 + 10;
int a[maxn], n;
int dp1[maxn], dp_max1[maxn], ans1;
int dp2[maxn], dp_min2[maxn], ans2;
int main()
{
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("c.in", "r", stdin);
#endif
    int tmp;
    while (cin >> tmp)
    {
        a[++n] = tmp;
    }
    for (re int i = 1; i <= n; ++i)
    {
        int l = 0, r = ans1 + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (a[i] > dp_max1[mid])
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        dp1[i] = l + 1;
        dp_max1[dp1[i]] = a[i];
        ans1 = max(ans1, dp1[i]);
    }
    cout << ans1 << endl;
    for (re int i = 1; i <= n; ++i)
    {
        int l = 0, r = ans2 + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (dp_min2[mid] < a[i])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        dp2[i] = l + 1;
        dp_min2[dp2[i]] = a[i];
        ans2 = max(ans2, dp2[i]);
    }
    cout << ans2 << endl;
    return 0;
}