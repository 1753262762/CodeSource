#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 100 + 10;
int dp[maxn << 1][maxn << 1], dp2[maxn << 1][maxn << 1], x[maxn << 1];
int arr[maxn << 1];
int main()
{
    int n;
    cin >> n;
    memset(dp2, 0x3f, sizeof(dp2));
    for (re int i = 1; i <= n; ++i)
    {
        cin >> x[i];
        x[i + n] = x[i];
    }
    for (re int i = 1; i <= (n << 1); ++i)
    {
        arr[i] = arr[i - 1] + x[i];
        dp2[i][i] = 0;
    }
    for (re int len = 2; len <= n; ++len)
    {
        for (re int i = 1; i + len - 1 <= 2 * n; ++i)
        {
            int j = i + len - 1;
            for (re int k = i; k < j; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[j] - arr[i - 1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + arr[j] - arr[i - 1]);
            }
        }
    }
    int ans_max = -1, ans_min = 0x3f3f3f;
    for (re int i = 1; i <= n; ++i)
    {
        ans_max = max(ans_max, dp[i][i + n - 1]);
        ans_min = min(ans_min, dp2[i][i + n - 1]);
    }
    cout << ans_min << endl;
    cout << ans_max << endl;
    return 0;
}