#include <bits/stdc++.h>
using namespace std;

const int Maxn = 15 + 5;
const int INF = 0x3f3f3f3f;
#define re register

struct node
{
    double x, y;
} a[Maxn];

int n, cnt = 0;
double Dis[Maxn][Maxn], ans = INF;
bool Book[Maxn];
void dfs(int Dep, double Cnt, int Now)
{
    if (++cnt > 80000000)
    {
        printf("%.2f\n", ans);
        exit(0);
    }
    if (Dep == n + 1)
        ans = min(ans, Cnt);
    if (Cnt > ans)
        return;
    for (re int i = 2; i <= n + 1; ++i)
    {
        if (!Book[i])
        {
            Book[i] = 1;
            dfs(Dep + 1, Cnt + Dis[Now][i], i);
            Book[i] = 0;
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin >> n;
    a[1] = (node){0, 0}, Book[1] = 1;
    for (re int i = 2; i <= n + 1; ++i)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (re int i = 1; i <= n + 1; ++i)
    {
        for (re int j = 1; j <= n + 1; ++j)
        {
            if (i != j)
                Dis[i][j] = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
        }
    }
    dfs(1, 0, 1);
    printf("%.2f\n", ans);
    return 0;
}