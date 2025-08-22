#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 40;
int Map[maxn][maxn];
int main()
{
    int n;
    cin >> n;
    int before_x = 1, before_y = n / 2 + 1;
    Map[before_x][before_y] = 1;
    for (re int i = 2; i <= n * n; ++i)
    {
        // 规定x为行y为列
        int now_x, now_y;
        if (before_x == 1 and before_y != n)
            now_x = n, now_y = before_y + 1;
        else if (before_x != 1 and before_y == n)
            now_x = before_x - 1, now_y = 1;
        else if (before_x == 1 and before_y == n)
            now_x = before_x + 1, now_y = before_y;
        else if (!Map[before_x - 1][before_y + 1])
            now_x = before_x - 1, now_y = before_y + 1;
        else
            now_x = before_x + 1, now_y = before_y;
        Map[now_x][now_y] = i;
        before_x = now_x, before_y = now_y;
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            cout << Map[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}