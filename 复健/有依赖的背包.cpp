#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 32005;

int fa_weight[maxn];
int fa_value[maxn];
int son_weight[maxn][3];
int son_value[maxn][3];
int cnt[maxn];
int dp[maxn];
int main()
{
    int n, m;
    cin >> m >> n;
    for (re int i = 1; i <= n; ++i)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q)
        {
            fa_value[i] = v * p;
            fa_weight[i] = v;
        }
        else
        {
            son_value[q][++cnt[q]] = v * p;
            son_weight[q][cnt[q]] = v;
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = m; fa_weight[i] != 0 and j >= fa_weight[i]; --j)
        {
            dp[j] = max(dp[j - fa_weight[i]] + fa_value[i], dp[j]);
            if (j >= fa_weight[i] + son_weight[i][1])
            {
                dp[j] = max(dp[j - fa_weight[i] - son_weight[i][1]] + fa_value[i] + son_value[i][1], dp[j]);
            }
            if (j >= fa_weight[i] + son_weight[i][2])
            {
                dp[j] = max(dp[j - fa_weight[i] - son_weight[i][2]] + fa_value[i] + son_value[i][2], dp[j]);
            }
            if (j >= fa_weight[i] + son_weight[i][1] + son_weight[i][2])
            {
                dp[j] = max(dp[j - fa_weight[i] - son_weight[i][1] - son_weight[i][2]] + fa_value[i] + son_value[i][1] + son_value[i][2], dp[j]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}