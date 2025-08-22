#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
#define re register
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (re int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            cout << a[i] << endl;
            return 0;
        }
    }
    return 0;
}