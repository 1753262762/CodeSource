#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int z = y - x;
        if (z < 0)
        {
            cout << "No" << endl;
        }
        else if (z == 0)
        {
            cout << "Yes" << endl;
        }
        else
            cout << (n - m + x >= y ? "Yes" : "No") << endl;
    }
    return 0;
}