#include <bits/stdc++.h>
using namespace std;
#define re register
const int maxn = 1e5 + 10;
int a[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (re int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        cout << a[n / 2 + 1] << endl;
    }
    return 0;
}