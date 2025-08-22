#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 2e4 + 10;
const int maxm = 1e5 + 10;

struct node
{
    int to, next;
} edge[maxm << 1];
int head[maxm << 1], cnt = 0;
void make_edge(int from, int to)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}
void add(int from, int to)
{
    make_edge(from, to);
    make_edge(to, from);
}
int dfn[maxn], low[maxn], cnt_dfn = 0;
bool vis[maxn];
bool cut[maxn];
void dfs(int x, int fa)
{
    dfn[x] = low[x] = ++cnt_dfn;
    vis[x] = 1;
    int child = 0;
    for (re int i = head[x]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (!vis[to])
        {
            dfs(to, x);
            low[x] = min(low[x], low[to]);
            if (low[to] >= dfn[x] and x != fa)
            {
                cut[x] = 1;
            }
            if (x == fa)
            {
                ++child;
            }
        }
        else
        {
            low[x] = min(low[x], dfn[to]);
        }
    }
    if (child >= 2 and x == fa)
    {
        cut[x] = 1;
    }
}
int main()
{
    freopen("b.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (re int i = 1; i <= m; ++i)
    {
        int tmpu, tmpv;
        cin >> tmpu >> tmpv;
        add(tmpu, tmpv);
    }
    for (re int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            dfs(i, i);
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        if (cut[i])
            ans++;
    }
    cout << ans << endl;
    for (re int i = 1; i <= n; ++i)
    {
        if (cut[i])
            cout << i << ' ';
    }
    return 0;
}