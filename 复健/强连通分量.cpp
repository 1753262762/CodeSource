#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
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
int dfn[maxn], low[maxn], cnt_dfn = 0, vis[maxn];
bool flag[maxn];
stack<int> s;
int ans[10000][maxn], cnt1, cnt2[maxn];
bool if_cout[maxn];
int id[maxn];
void dfs(int x)
{
    flag[x] = 1;
    dfn[x] = low[x] = ++cnt_dfn;
    vis[x] = 1;
    s.push(x);
    for (re int i = head[x]; i; i = edge[i].next)
    {
        if (!dfn[edge[i].to])
        {
            dfs(edge[i].to);
            low[x] = min(low[x], low[edge[i].to]);
        }
        else if (vis[edge[i].to])
        {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
    if (low[x] == dfn[x])
    {
        ++cnt1;
        while (1)
        {
            int node = s.top();
            s.pop();
            vis[node] = 0;
            id[node] = cnt1;
            ans[cnt1][++cnt2[cnt1]] = node;
            // cout << node << ' ';
            if (node == x)
                break;
        }
    }
}
int main()
{
    freopen("b.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (re int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        make_edge(u, v);
    }
    for (re int i = 1; i <= n; ++i)
    {
        if (!flag[i])
            dfs(i);
    }
    cout << cnt1 << endl;
    for (re int i = 1; i <= n; ++i)
    {
        if (if_cout[i])
            continue;
        sort(ans[id[i]] + 1, ans[id[i]] + 1 + cnt2[id[i]]);
        for (re int j = 1; j <= cnt2[id[i]]; ++j)
        {
            cout << ans[id[i]][j] << ' ';
            if_cout[ans[id[i]][j]] = 1;
        }
        cout << endl;
    }
    return 0;
}