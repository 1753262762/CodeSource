#include <bits/stdc++.h>
using namespace std;
int t;
int a[10 + 5] = {0};
bool vis[10 + 5];
void dfs(int x)
{
    if (x > t)
    {
        for (int i = 1; i <= t; i++)
        {
            cout << "    " << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= t; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
            a[x] = 0;
        }
    }
}
int main()
{
    cin >> t;
    dfs(1);
    return 0;
}