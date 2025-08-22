#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 10;
const int maxm = 3e2 + 10;
#define re register
int a[maxn][maxm];
int arr1[maxn][maxn];
int arr2[maxm][maxm];
int sum1(int l, int r, int x)
{
    return arr1[x][r] - arr1[x][l - 1];
}
int sum2(int l, int r, int x)
{
    return arr2[x][r] - arr2[x][l - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        for (re int j = 1; j <= m; ++j)
        {
            arr1[i][j] = arr1[i][j - 1] + a[i][j];
        }
    }
    for (re int i = 1; i <= m; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            arr2[i][j] = arr2[i][j - 1] + a[j][i];
        }
    }
    int ans = 0;
    for (re int x2 = 1; x2 <= n; ++x2)
    {
        for (re int y2 = 1; y2 <= m; ++y2)
        {
            for (re int x1 = 1; x1 < x2; ++x1)
            {
                int y1 = y2 - (x2 - x1);
                if (y1 <= 0)
                    continue;
                int sum = 0;
                if (x2 - x1 == 1)
                {
                    sum = a[x1][y1] + a[x1][y2] + a[x2][y1] + a[x2][y2];
                    ans = max(ans, a[x1][y1] + a[x1][y2] + a[x2][y1] + a[x2][y2]);
                }
                else
                {
                    sum = sum1(x1, x2, y1) + sum2(x1, x2, y2) + sum1(y1, y2, x2) + sum2(y1, y2, x1) - a[x1][y1] - a[x1][y2] - a[x2][y2] - a[x2][y1];
                    ans = max(sum1(x1, x2, y1) + sum2(x1, x2, y2) + sum1(y1, y2, x2) + sum2(y1, y2, x1) - a[x1][y1] - a[x1][y2] - a[x2][y2] - a[x2][y1], ans);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}