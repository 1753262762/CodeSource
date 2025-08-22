#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define re register
int x[maxn];
int c[maxn];
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
    int ans2 = 0;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= i; ++j)
        {
            for (re int k = j; k <= i; ++k)
            {
                c[k]++;
                ans2 += x[k];
            }
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        cout << i * (n + 1 - i) << ' ';
        ans += (i * (n + 1 - i)) * x[i];
    }
    cout << endl;
    for (re int i = 1; i <= n; ++i)
    {
        cout << c[i] << ' ';
    }
    cout << endl
         << ans << endl;
    cout << ans2 << endl;
    return 0;
}