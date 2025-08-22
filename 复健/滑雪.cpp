/*
cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            cin >> Map[i][j];
        }
    }
警钟长鸣
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
#define re register

int Map[maxn][maxn];
int change_x[] = {0, 1, -1, 0, 0};
int change_y[] = {0, 0, 0, 1, -1};
int f[maxn][maxn];
int n, m;
int dfs(int x, int y)
{
    if (f[x][y])
        return f[x][y];
    bool if_move = 0;
    for (re int i = 1; i <= 4; ++i)
    {
        if (x + change_x[i] <= n and x + change_x[i] >= 1)
        {
            if (y + change_y[i] <= m and y + change_y[i] >= 1)
            {
                if (Map[x][y] > Map[x + change_x[i]][y + change_y[i]])
                {
                    if_move = 1;
                    f[x][y] = max(f[x][y], dfs(x + change_x[i], y + change_y[i]) + 1);
                }
            }
        }
    }
    if (if_move == 0)
    {
        f[x][y] = max(1, f[x][y]);
    }
    return f[x][y];
}
int main()
{
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= m; ++j)
        {
            cin >> Map[i][j];
        }
    }
    for (re int i = 1; i <= n; i++)
    {
        for (re int j = 1; j <= m; j++)
        {
            if (!f[i][j])
                dfs(i, j);
        }
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= m; ++j)
        {
            ans = max(f[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}