#include <bits/stdc++.h>
using namespace std;

const int maxn = 6 + 5;
#define re register
int ans[maxn], cnt;
int vis_1[maxn], vis_2[maxn], vis_3[maxn], vis_4[maxn];
void dfs(int dep)
{
    if (dep > 6)
    {
        for (re int i = 1; i <= cnt; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (re int i = 1; i <= 6; ++i)
    {
        if (1)
        {
            vis_1[dep] = 1;
            vis_2[i] = 1;
        }
    }
}
int main()
{
    float x = 2.0, y;

    if (x < 0.0)
        y = 0.0;

    else if (x < 10.0)
        y = 1.0 / x;

    else
        y = 1.0;

    printf("%f\n", y);
}