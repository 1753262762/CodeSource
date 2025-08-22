#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000;
const int maxm = 200000;

struct node
{
    int from, to, cost;
    void input()
    {
        cin >> from >> to >> cost;
    }
} edge[maxm];
bool cmp(node x, node y)
{
    return x.cost < y.cost;
}

int fa[maxm];
bool find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int join(int x, int y)
{
    if (find(x) != find(y))
    {
        fa[find(y)] = find(x);
        return 1;
    }
    return 0;
}
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        edge[i].input();
    }
    sort(edge + 1, edge + 1 + m, cmp);
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (cnt == n - 1)
            break;
        if (join(edge[i].from, edge[i].to))
        {
            ans += edge[i].cost;
            ++cnt;
        }
    }
    cout << ans << endl;
    return 0;
}