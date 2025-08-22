#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int maxm = 1000 + 5;
const int maxk = 100 + 5;
#define re register
struct goods
{
    int value, weight;
} x[maxn];
int Book[maxk][maxn], cnt[maxn], dp[maxm];
int main()
{
    int n, m, c = 0;
    cin >> m >> n;
    for (re int i = 1; i <= n; ++i)
    {
        int place;
        cin >> x[i].weight >> x[i].value >> place;
        Book[place][++cnt[place]] = i;
        c = max(c, place);
    }
    for (re int i = 1; i <= c; ++i)
    {
        for (re int j = m; j >= 0; --j)
        {
            for (re int k = 1; k <= cnt[i]; ++k)
            {
                if (j - x[Book[i][k]].weight >= 0)
                    dp[j] = max(dp[j - x[Book[i][k]].weight] + x[Book[i][k]].value, dp[j]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}