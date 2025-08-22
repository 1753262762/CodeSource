#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
#define re register

struct node
{
    int x, y, dis;
    void input()
    {
        cin >> x >> y;
        dis = 0;
    }
};
bool Map[maxn][maxn];
int f[maxn][maxn];
int change_x[4] = {1, -1, 0, 0};
int change_y[4] = {0, 0, 1, -1};
int main()
{
    int n, m, Time;
    cin >> n >> m >> Time;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= m; ++j)
        {
            char ss;
            cin >> ss;
            if (ss == '*')
            {
                Map[i][j] = 1;
            }
        }
    }
    node from, to;
    from.input(), to.input();
    queue<node> Q;
    Q.push(from);
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        if (now.dis > Time)
            continue;
        for (re int i = 0; i <= 3; ++i)
        {
            if (now.x + change_x[i] > n or now.x + change_x[i] < 1)
                continue;
            if (now.y + change_y[i] > m or now.y + change_y[i] < 1)
                continue;
            if (Map[now.x + change_x[i]][now.y + change_y[i]])
                continue;
            f[now.x + change_x[i]][now.y + change_y[i]]++;
            node next;
            next.x = now.x + change_x[i];
            next.y = now.y + change_y[i];
            next.dis = now.dis + 1;
            Q.push(next);
        }
    }
    cout << f[to.x][to.y] << endl;
    return 0;
}