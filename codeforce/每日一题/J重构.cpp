#include <bits/stdc++.h>
using namespace std;
#define re register
int main()
{
    ios::sync_with_stdio();
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        if (l & 1)
        {
            cout << (r - l + 2) / 4 << endl;
        }
        else
        {
            cout << (r - l + 1) / 4 << endl;
        }
    }

    return 0;
}