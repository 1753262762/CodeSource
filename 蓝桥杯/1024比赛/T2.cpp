#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("T2.in", "r", stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        cout << (n / k) * (m / k) << endl;
    }
    return 0;
}