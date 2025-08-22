#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxt = 3e5 + 10;

int f[maxt];
int main()
{
    int m, s, t;
    cin >> m >> s >> t;
    for (re int i = 1; i <= t; ++i)
    {
        if (m >= 10)
        {
            m -= 10;
            f[i] = f[i - 1] + 60;
        }
        else
        {
            m += 4;
            f[i] = f[i - 1];
        }
    }
    for (re int i = 1; i <= t; ++i)
    {
        f[i] = max(f[i - 1] + 17, f[i]);
        if (f[i] >= s)
        {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    cout << f[t] << endl;
    return 0;
}