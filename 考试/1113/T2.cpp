#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
#define re register
int a[maxn];
bool check(int l, int r)
{
    int cnt = 0;
    while (l <= r)
    {
        if (cnt > 1)
        {
            return 0;
        }
        if (a[l] != a[r])
        {
            ++cnt;
        }
        ++l, --r;
    }
    if (cnt == 1)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (re int i = 1; i <= n and i + k - 1 <= n; ++i)
    {
        int l = i, r = i + k - 1;
        ans += check(l, r);
    }
    cout << ans << endl;
    return 0;
}