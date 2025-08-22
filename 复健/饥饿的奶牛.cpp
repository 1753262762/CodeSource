#include <bits/stdc++.h>
using namespace std;

const int maxn = 150000 + 10;
#define re register
struct node
{
    int l, r, sum;
    void input(int x, int y)
    {
        l = x, r = y, sum = y - x + 1;
    }
} a[maxn];
bool cmp(node x, node y)
{
    return x.r < y.r;
}
int dp[maxn];
int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("c.in", "r", stdin);
#endif
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        a[i].input(tmpx, tmpy);
    }
    sort(a + 1, a + 1 + n, cmp);
    for (re int i = 1; i <= n; ++i)
    {
        dp[i] = a[i].sum;
        int l = 1, r = i - 1, j = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[i].l > a[mid].r)
            {
                j = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], dp[j] + a[i].sum);
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}