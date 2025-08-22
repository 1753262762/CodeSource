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

void initializePositions()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> Map[i][j];
            switch (Map[i][j])
            {
            case 'S':
                from = {i, j};
                break;
            case 'E':
                to = {i, j};
                break;
            case 'D':
                dool = {i, j};
                break;
            case 'K':
                key = {i, j};
                break;
            }
        }
    }
}

void bfs(node start, char reachable[], int &local_depth[])
{
    memset(vis, 0, sizeof(vis));
    memset(local_depth, 0, sizeof(dep));
    queue<node> Q;
    Q.push(start);
    vis[start.x][start.y] = 1;

    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int to_x = now.x + change_x[i], to_y = now.y + change_y[i];
            if (to_x >= 1 && to_x <= n && to_y >= 1 && to_y <= m)
            {
                if (!vis[to_x][to_y] && strchr(reachable, Map[to_x][to_y]))
                {
                    local_depth[to_x][to_y] = local_depth[now.x][now.y] + 1;
                    vis[to_x][to_y] = 1;
                    Q.push({to_x, to_y});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    initializePositions();

    int local_dep[maxn][maxn];
    bfs(from, ".EK", local_dep);

    if (local_dep[to.x][to.y])
    {
        cout << local_dep[to.x][to.y] << endl;
        return 0;
    }
    else
    {
        int ans = local_dep[key.x][key.y];
        bfs(key, ".DSE", local_dep);
        if (local_dep[to.x][to.y])
            cout << ans + local_dep[to.x][to.y] << endl;
        else
            cout << -1;
    }

    return 0;
}
