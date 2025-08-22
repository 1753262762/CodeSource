#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve()
{

    i64 a, b;
    cin >> a >> b;

    i64 l = 1, r = 1e9, ans = 0;
    while (l <= r)
    {
        i64 mid = l + r >> 1;
        if ((1 + mid) * mid <= (b - a) * 2)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}