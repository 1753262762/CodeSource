#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int ans = 0;
        int i = 1, j = 1;
        while (j <= n)
        {
            if (a[j] - a[i] <= k)
            {
                ans = max(ans, j - i + 1);
                ++j;
            }
            else
            {
                ++i;
                if (i > j)
                {
                    j = i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}