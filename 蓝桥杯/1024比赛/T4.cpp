#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
#define re register
int a[maxn];
int main()
{
    freopen("T4.in", "r", stdin);
    int n, q;
    cin >> n >> q;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int opt;
        cin >> opt;
        for (re int i = 1; opt * i <= n; ++i)
        {
            a[opt * i] = a[opt * i] * 10 % 24;
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }
    return 0;
}