#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1e3 + 10;
bool a[maxn][maxn];
void reX(int x)
{
    for (int j = 1; j <= m; j++)
    {
        a[x][j] = !a[x][j];
    }
}
int cnt(int i, int j)
{
    int res = 0;
    if (i - 1 >= 1)
    {
        res += a[i - 1][j] & a[i][j];
        res += !a[i - 1][j] & !a[i][j];
    }
    if (i + 1 <= n)
    {
        res += a[i + 1][j] & a[i][j];
        res += !a[i + 1][j] & !a[i][j];
    }
    if (j - 1 >= 1)
    {
        res += a[i][j - 1] & a[i][j];
        res += !a[i][j - 1] & !a[i][j];
    }
    if (j + 1 <= m)
    {
        res += a[i][j + 1] & a[i][j];
        res += !a[i][j + 1] & !a[i][j];
    }
    return res * res;
}
char s[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int len = strlen(s);
        for (int j = 0; j < len; j++)
        {
            if (s[j] == '1')
            {
                a[i][j + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int res1 = 0;
        for (int j = 1; j <= m; ++j)
        {
            res1 += cnt(i, j);
        }
        if (i - 1 >= 1)
        {
            for (int j = 1; j <= m; j++)
            {
                res1 += cnt(i - 1, j);
            }
        }
        if (i + 1 <= n)
        {
            for (int j = 1; j <= m; j++)
            {
                res1 += cnt(i + 1, j);
            }
        }
        reX(i);
        int res2 = 0;
        for (int j = 1; j <= m; ++j)
        {
            res2 += cnt(i, j);
        }
        if (i - 1 >= 1)
        {
            for (int j = 1; j <= m; j++)
            {
                res2 += cnt(i - 1, j);
            }
        }
        if (i + 1 <= n)
        {
            for (int j = 1; j <= m; j++)
            {
                res2 += cnt(i + 1, j);
            }
        }
        if (res1 > res2)
        {
            reX(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += cnt(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}