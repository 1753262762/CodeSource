#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0;
int a[105][105] = {0};
bool vis[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (a[nx][ny] == 0 || vis[nx][ny] == 1)
            continue;
        dfs(nx, ny);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != 0 && vis[i][j] == 0)
            {
                dfs(i, j);
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}