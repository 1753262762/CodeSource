#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 3 + 1;
int a[maxn];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int sum = 0;
        for (re int i = 1; i <= 3; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2)
        {
            cout << -1 << endl;
            continue;
        }
        if (a[1] + a[2] >= a[3])
        {
            cout << sum / 2 << endl;
        }
        else
            cout << a[1] + a[2] << endl;
    }
    return 0;
}