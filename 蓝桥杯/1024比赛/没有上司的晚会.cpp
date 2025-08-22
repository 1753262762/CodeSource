#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e3 + 5;
#define re register

struct node
{
    int next, to;
} edge[maxn];
int head[maxn], cnt;
void make_edge(int from, int to)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}

bool vis[maxn];
int a[maxn], n;
int go[maxn], disgo[maxn];

void dfs(int x)
{
    vis[x] = 1;
    go[x] = a[x];
    for (re int i = head[x]; i != 0; i = edge[i].next)
    {
        int y = edge[i].to;
        if (!vis[y])
        {
            dfs(y);
        }
        go[x] += disgo[y];
        disgo[x] += max(disgo[y], go[y]);
    }
}

int main()
{
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (re int i = 1; i < n; ++i)
    {
        int tmp_fa, tmp_son;
        cin >> tmp_son >> tmp_fa;
        make_edge(tmp_fa, tmp_son);
    }
    for (re int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            dfs(i);
    }
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        ans = max(ans, max(go[i], disgo[i]));
    }
    cout << ans << endl;
    return 0;
}