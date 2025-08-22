#include <bits/stdc++.h>
using namespace std;
const int maxm = 100 + 5;
const int maxn = 1000 + 5;
#define re register
int Map[maxm][maxm];
int change_x[] = {0, 0, 0, 1, -1, 1, 1, -1, -1, 2, -2, 0, 0};
int change_y[] = {0, 1, -1, 0, 0, 1, -1, 1, -1, 0, 0, 2, -2};
/*
注意 还有一种大跳情况没写
*/
/*
异色cost 1
异色斜对角cost 3
同色斜对角cost 2
*/
struct node
{
    int x, y, cost;
};
int f[maxm][maxm];
int main()
{
    int m, n;
    cin >> m >> n;
    memset(Map, -1, sizeof(Map));
    memset(f, 0x3f, sizeof(f));
    f[1][1] = 0;
    for (re int i = 1; i <= n; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        Map[x][y] = c;
    }
    node Begin = (node){1, 1, 0};
    queue<node> Q;
    Q.push(Begin);
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        for (re int i = 1; i <= 4; ++i)
        {
            if (now.x + change_x[i] > m or now.x + change_x[i] < 1)
                continue;
            if (now.y + change_y[i] > m or now.y + change_y[i] < 1)
                continue;
            if (Map[now.x + change_x[i]][now.y + change_y[i]] == -1)
                continue;
            int cost = 0;
            if (Map[now.x][now.y] != Map[now.x + change_x[i]][now.y + change_y[i]])
            {
                ++cost;
            }
            if (now.cost + cost < f[now.x + change_x[i]][now.y + change_y[i]])
            {
                Q.push(node{now.x + change_x[i], now.y + change_y[i], now.cost + cost});
                f[now.x + change_x[i]][now.y + change_y[i]] = now.cost + cost;
            }
        }
        for (re int i = 4; i <= 12; ++i)
        {
            if (now.x + change_x[i] > m or now.x + change_x[i] < 1)
                continue;
            if (now.y + change_y[i] > m or now.y + change_y[i] < 1)
                continue;
            if (Map[now.x + change_x[i]][now.y + change_y[i]] == -1)
                continue;
            int cost = 2;
            if (Map[now.x][now.y] != Map[now.x + change_x[i]][now.y + change_y[i]])
            {
                ++cost;
            }
            if (now.cost + cost < f[now.x + change_x[i]][now.y + change_y[i]])
            {
                Q.push(node{now.x + change_x[i], now.y + change_y[i], now.cost + cost});
                f[now.x + change_x[i]][now.y + change_y[i]] = now.cost + cost;
            }
        }
    }
    if (f[m][m] != 1061109567)
    {
        cout << f[m][m] << endl;
        return 0;
    }
    if (Map[m][m] = -1)
    {
        if (min(f[m][m - 1], min(f[m - 1][m], f[m - 1][m - 1])) != 1061109567)
        {
            cout << min(f[m][m - 1], f[m - 1][m]) + 2;
            return 0;
        }
    }
    if (f[m][m] == 1061109567)
        cout << -1 << ' ';
    else
        cout << f[m][m] << ' ';
    return 0;
}