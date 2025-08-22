#include <bits/stdc++.h>
using namespace std;
#define re register
const int maxn = 1e5 + 10;
int n, m;
int x[maxn], sum[maxn];
long long ans = 0;
int main()
{
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    for (re int i = 1; i < n; ++i)
    {
        sum[i] = abs(x[i + 1] * x[i + 1] - x[i] * x[i]);
    }
    long long cnt1 = 0;
    for (re int i = 1; i <= m - 1; ++i)
    {
        cnt1 += sum[i];
    }
    ans = cnt1;
    for (re int i = m; i < n; ++i)
    {
        cnt1 += sum[i] - sum[i - m + 1];
        ans = min(ans, cnt1);
    }
    cout << ans << endl;
    return 0;
}