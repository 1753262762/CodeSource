#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 1000 + 10;
bool vis[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0, ans = 0;
    for (re int i = 1; ans < n; ++i)
    {
        if (i > n)
        {
            i = 1;
        }
        if (vis[i])
            continue;
        cnt++;
        if (cnt == m)
        {
            cnt = 0;
            ans++;
            vis[i] = 1;
            cout << i << ' ';
        }
    }
    return 0;
}