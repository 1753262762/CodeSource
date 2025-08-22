#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 10;
const int maxm = 1e5 + 10;
#define re register

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
void add(int u, int v)
{
    make_edge(u, v);
    make_edge(v, u);
}
int low[maxn], dfn[maxn], cnt_dfn = 0;
bool cut[maxn], vis[maxn];
int cnt_ans = 0;
void dfs(int x, int fa)
{
    low[x] = dfn[x] = ++cnt_dfn;
    vis[x] = 1;
    int child = 0;
    for (re int i = head[x]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (!vis[to])
        {
            dfs(to, x);
            low[x] = min(low[x], low[to]);
            if (x == fa)
                ++child;
            if (x != fa and low[to] >= dfn[x])
                cut[x] = 1;
        }
        else
        {
            low[x] = min(low[x], dfn[to]);
        }
    }
    if (x == fa and child >= 2)
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
    for (re int i = 1; i <= n; ++i)
    {
        if (cut[i])
            ++cnt_ans;
    }
    cout << cnt_ans << endl;
    for (re int i = 1; i <= n; ++i)
    {
        if (cut[i])
            cout << i << ' ';
    }
    return 0;
}