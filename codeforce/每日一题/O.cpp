#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxm = 4 + 1;
const int maxn = 500 + 5;
int ans[maxn], cnt;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        char ss;
        for (re int i = 1; i <= n; ++i)
        {
            for (re int j = 1; j <= 4; ++j)
            {
                cin >> ss;
                if (ss == '#')
                {
                    ans[++cnt] = j;
                }
            }
        }
        while (cnt >= 1)
        {
            cout << ans[cnt--] << ' ';
        }
        cout << endl;
    }
    return 0;
}