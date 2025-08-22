#include <bits/stdc++.h>
using namespace std;
#define re register
int main()
{
    freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int cnt = 0;
        for (re int i = 1; i <= k / 2; ++i)
        {
            cout << x - i << ' ' << y - i << endl;
            cout << x + i << ' ' << y + i << endl;
        }
        if (k & 1)
            cout << x << ' ' << y << endl;
    }
    return 0;
}