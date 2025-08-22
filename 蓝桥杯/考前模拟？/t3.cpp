#include <bits/stdc++.h>
using namespace std;
#define re register
int ans = 0;
int main()
{
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        int queryNum;
        cin >> queryNum;
        ans += queryNum == 1 ? 0 : 1;
    }
    cout << ans << endl;
    return 0;
}
