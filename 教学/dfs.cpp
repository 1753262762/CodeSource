#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 10 + 5;
bool vis[maxn];
int ans[maxn], cnt = 0;
int n;
void dfs(int dep)
{
    if (dep > n)
    {
        for (re int i = 1; i <= n; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (re int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            ans[++cnt] = i;
            dfs(dep + 1);
            ans[cnt--] = 0;
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}