#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
#define re register
bool vis[maxn];
int main()
{
    int L, M;
    cin >> L >> M;
    while (M--)
    {
        int l, r;
        cin >> l >> r;
        for (re int i = l; i <= r; ++i)
        {
            vis[i] = 1;
        }
    }
    int ans = 0;
    for (re int i = 0; i <= L; ++i)
    {
        if (!vis[i])
            ++ans;
    }
    cout << ans << endl;
    return 0;
}