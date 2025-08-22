#include <bits/stdc++.h>
using namespace std;
int a[10] = {0, 0, 1, 0, 0, 0, 1, 0, 0};
int main()
{
    int n, m;
    cin >> n >> m;
    int k = 1, e = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        k = e;
        for (int j = 1; j <= m; ++j)
        {
            ans += a[k];
            if (k == 7)
                k = 1;
            else
                k++;
        }
        if (e == 7)
            e = 1;
        else
            e++;
    }
    cout << ans << endl;
    return 0;
}