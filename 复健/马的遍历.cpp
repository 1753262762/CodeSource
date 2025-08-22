#include <bits/stdc++.h>
using namespace std;
const int Max_N = 400 + 5;
#define re register
inline int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int m, n, x, y;
int Ans[Max_N][Max_N];
struct Node
{
    int x, y;
};
int X_change[10] = {0,1,1,-1,-1,2,2,-2,-2};
int Y_change[10] = {0,2,-2,2,-2,1,-2,1,-2};
bool Book[Max_N][Max_N];
void bfs(int x, int y)
{
    queue<Node> Q;
    Q.push((Node){x, y});
    while (!Q.empty())
    {
        int tmp_x = Q.front().x, tmp_y = Q.front().y;
        Q.pop();
        cout<<tmp_x<<' '<<tmp_y<<endl;
        Book[tmp_x][tmp_y]=1;
        for (re int i = 1; i <= 4; ++i)
        {
            for (re int j = 1; j <= 4; ++j)
            {
                if (tmp_x + X_change[i] > 0 and tmp_x + X_change[i] <= m)
                {
                    if (tmp_y + Y_change[i] > 0 and tmp_y + Y_change[i] <= n)
                    {
                        if (!Book[tmp_x + X_change[i]][tmp_y + Y_change[i]])
                        {
                            Ans[tmp_x + X_change[i]][tmp_y + Y_change[i]] = Ans[tmp_x][tmp_y] + 1;
                            Q.push((Node){tmp_x + X_change[i], tmp_y + Y_change[i]});
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    m = read(), n = read(), x = read(), y = read();
    memset(Ans, 0x3f, sizeof(Ans));
    Ans[x][y] = 0, Book[Max_N][Max_N] = 1;
    bfs(x, y);
    for (re int i = 1; i <= m; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            cout << Ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}