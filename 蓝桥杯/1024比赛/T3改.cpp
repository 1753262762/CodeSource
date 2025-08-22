#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define re register
int x[maxn];
int main()
{
    freopen("T3.in", "r", stdin);
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        ans += (i * (n + 1 - i)) * x[i];
    }
    cout << ans << endl;
    return 0;
}