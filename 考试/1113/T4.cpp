#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
int Map[maxn][maxn];
int pre[maxn][maxn];
int n, k;

void make_pre()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            pre[i][j] = Map[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
}

int ask(int x, int y)
{
    return pre[x + k - 1][y + k - 1] - pre[x - 1][y + k - 1] - pre[x + k - 1][y - 1] + pre[x - 1][y - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> Map[i][j];
            }
        }

        make_pre();

        int ans = 0;
        for (int i = 1; i + k - 1 <= n; ++i)
        {
            for (int j = 1; j + k - 1 <= n; ++j)
            {
                ans = max(ask(i, j), ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
