#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
#define re register
int a[maxn];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (re int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        if (n < 3 and a[2] - a[1] > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}