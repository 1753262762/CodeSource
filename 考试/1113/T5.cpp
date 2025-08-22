#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
int n, m;
char Map[maxn][maxn];

struct node
{
    int x, y;
};
node from, to, dool, key;
bool vis[maxn][maxn];
int change_x[4] = {0, 0, -1, 1};
int change_y[4] = {1, -1, 0, 0};
int dep[maxn][maxn];

void bfs1()
{
    queue<node> Q;
    Q.push(from);
    vis[from.x][from.y] = 1;

    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int to_x = now.x + change_x[i], to_y = now.y + change_y[i];
            if (to_x >= 1 && to_x <= n && to_y >= 1 && to_y <= m)
            {
                if (!vis[to_x][to_y])
                {
                    if (Map[to_x][to_y] == '.' || Map[to_x][to_y] == 'E' || Map[to_x][to_y] == 'K')
                    {
                        dep[to_x][to_y] = dep[now.x][now.y] + 1;
                        vis[to_x][to_y] = 1;
                        Q.push({to_x, to_y});
                    }
                }
            }
        }
    }
}

void bfs2()
{
    queue<node> Q;
    Q.push(key);
    vis[key.x][key.y] = 1;

    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int to_x = now.x + change_x[i], to_y = now.y + change_y[i];
            if (to_x >= 1 && to_x <= n && to_y >= 1 && to_y <= m)
            {
                if (!vis[to_x][to_y])
                {
                    if (Map[to_x][to_y] == '.' || Map[to_x][to_y] == 'D' || Map[to_x][to_y] == 'S' || Map[to_x][to_y] == 'E')
                    {
                        dep[to_x][to_y] = dep[now.x][now.y] + 1;
                        vis[to_x][to_y] = 1;
                        Q.push({to_x, to_y});
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'S')
                from = {i, j};
            if (Map[i][j] == 'E')
                to = {i, j};
            if (Map[i][j] == 'D')
                dool = {i, j};
            if (Map[i][j] == 'K')
                key = {i, j};
        }
    }

    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    bfs1();
    int ans1;
    ans1 = dep[to.x][to.y];

    int ans2 = dep[key.x][key.y];
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    bfs2();
    ans2 += dep[to.x][to.y];
    if (ans1 == 0 and ans2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        if (ans1 != 0 and ans2 != 0)
        {
            cout << min(ans1, ans2) << endl;
        }
        else if (ans1 == 0)
        {
            cout << ans2 << endl;
        }
        else
        {
            cout << ans1 << endl;
        }
    }
    return 0;
}
