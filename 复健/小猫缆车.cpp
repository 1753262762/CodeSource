#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 5;
const int INF = 0x3f3f3f;
#define re register

bool cmp(int x, int y)
{
    return x > y;
}
int a[maxn], sum[maxn];
int n, k, ans = INF;
void dfs(int dep, int cnt_box)
{
    if (cnt_box >= ans)
        return;
    if (dep > n)
    {
        ans = min(ans, cnt_box);
        return;
    }
    for (re int i = 1; i <= cnt_box; ++i)
    {
        if (sum[i] >= a[dep])
        {
            sum[i] -= a[dep];
            dfs(dep + 1, cnt_box);
            sum[i] += a[dep];
        }
    }
    sum[cnt_box + 1] = k - a[dep];
    dfs(dep + 1, cnt_box + 1);
}
int main()
{
    cin >> n >> k;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    sum[1] = k;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}