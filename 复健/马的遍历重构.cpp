    #include <bits/stdc++.h>
    using namespace std;

    const int Maxn = 400 + 5;
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

    struct node
    {
        int x, y;
        int dep;
    };

    int n, m, x, y;
    bool book[Maxn][Maxn];
    int Ans[Maxn][Maxn];
    int X_change[10] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
    int Y_change[10] = {0, 2, 1, -1, -2, 2, 1, -1, -2};
    void bfs()
    {
        queue<node> Q;
        Q.push((node){x, y, 0});
        book[x][y] = 1;
        Ans[x][y] = 0;
        while (!Q.empty())
        {
            int now_x = Q.front().x, now_y = Q.front().y, Dep = Q.front().dep;
            // cout << now_x << ' ' << now_y << endl;
            Q.pop();
            for (re int i = 1; i <= 8; ++i)
            {
                if (now_x + X_change[i] > 0 and now_x + X_change[i] <= n)
                {
                    if (now_y + Y_change[i] > 0 and now_y + Y_change[i] <= m)
                    {
                        // cout << now_x + X_change[i] << ' ' << now_y + Y_change[i] << endl;
                        if (!book[now_x + X_change[i]][now_y + Y_change[i]])
                        {
                            book[now_x + X_change[i]][now_y + Y_change[i]] = 1;
                            Ans[now_x + X_change[i]][now_y + Y_change[i]] = Dep + 1;
                            Q.push((node){now_x + X_change[i], now_y + Y_change[i], Dep + 1});
                        }
                    }
                }
            }
        }
    }
    int main()
    {
        n = read(), m = read(), x = read(), y = read();
        bfs();
        for (re int i = 1; i <= n; ++i)
        {
            for (re int j = 1; j <= m; ++j)
            {
                if (!Ans[i][j])
                {
                    if (i == x and j == y)
                        cout << 0 << ' ';
                    else
                        cout << -1 << ' ';
                }
                else
                    cout << Ans[i][j] << ' ';
            }
            cout << endl;
        }
        return 0;
    }