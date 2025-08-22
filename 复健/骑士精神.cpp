#include <bits/stdc++.h>
using namespace std;

const int maxm = 5 + 2;
const int max_step = 15;
#define re register
int Map[maxm][maxm];
int need_map[maxm][maxm] = {{}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}, {0, 0, 0, -1, 1, 1}, {0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}};
int change_x[] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
int change_y[] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
bool win;
int now_dep = 1;
bool if_change[maxm][maxm];
void init()
{
    memset(if_change, 0, sizeof(if_change));
    memset(Map, 0, sizeof(Map));
    win = 0;
    now_dep = 1;
    for (re int i = 1; i <= 5; ++i)
    {
        for (re int j = 1; j <= 5; ++j)
        {
            char ss = getchar();
            if (ss == '*')
            {
                Map[i][j] = -1;
            }
            else if (ss == '1')
            {
                Map[i][j] = 1;
            }
            else if (ss == '0')
            {
                Map[i][j] = 0;
            }
        }
        getchar();
    }
}
void output()
{
    for (re int i = 1; i <= 5; ++i)
    {
        for (re int j = 1; j <= 5; ++j)
        {
            cout << Map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool if_win()
{
    for (re int i = 1; i <= 5; ++i)
    {
        for (re int j = 1; j <= 5; ++j)
        {
            if (Map[i][j] != need_map[i][j])
                return 0;
        }
    }
    return 1;
}
void dfs(int dep)
{
    if (win)
        return;
    if (dep == now_dep)
    {
        if (if_win())
        {
            win = 1;
            cout << dep << endl;
            return;
        }
        return;
    }
    for (re int i = 1; i <= 5; ++i)
    {
        for (re int j = 1; j <= 5; ++j)
        {
            for (re int k = 1; k <= 8; ++k)
            {
                if (if_change[i][j] == 1)
                    continue;
                if (if_change[i + change_x[k]][j + change_y[k]] == 1)
                    continue;
                if (i + change_x[k] > 5 or i + change_x[k] < 1)
                    continue;
                if (j + change_y[k] > 5 or j + change_y[k] < 1)
                    continue;
                swap(Map[i][j], Map[i + change_x[k]][j + change_y[k]]);
                if_change[i][j] = 1;
                if_change[i + change_x[k]][j + change_y[k]] = 1;
                dfs(dep + 1);
                if_change[i][j] = 0;
                if_change[i + change_x[k]][j + change_y[k]] = 0;
                swap(Map[i][j], Map[i + change_x[k]][j + change_y[k]]);
            }
        }
    }
    dfs(dep + 1);
}
void sovle()
{
    init();
    while (1)
    {
        cout << now_dep << endl;
        if (now_dep > max_step)
            break;
        dfs(0);
        if (win)
            break;
        ++now_dep;
    }
    // output();
}
int main()
{
    freopen("a.in", "r", stdin);
    int T;
    cin >> T;
    getchar();
    while (T--)
    {
        sovle();
    }
    return 0;
}