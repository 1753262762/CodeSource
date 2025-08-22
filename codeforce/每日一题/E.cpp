#include <bits/stdc++.h>
using namespace std;
#define re register
const int maxn = 2e5 + 10;
bool vis[maxn];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        int n;
        cin >> n;
        bool flag = 0;
        int tmp;
        cin >> tmp;
        vis[tmp] = 1;
        for (re int i = 1; i < n; ++i)
        {
            cin >> tmp;
            if (vis[tmp])
            {
                flag = 1;
            }
            if (!(vis[tmp - 1] or vis[tmp + 1]))
            {
                flag = 1;
            }
            vis[tmp] = 1;
        }
        if (!flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}