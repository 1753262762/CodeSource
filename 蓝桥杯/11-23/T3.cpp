#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << (3 ^ 5) << endl;
    int ans = 0;
    for (int i = 1; i <= 2024; ++i)
    {
        if ((i ^ 2024) < 2024)
        {
            ans++;
            // cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}