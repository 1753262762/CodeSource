#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 5;
const int maxm = 300 + 5;
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
int val[maxn], dp[maxn][maxm];
void dfs(int now, int tot)
{
    if (tot == 0)
        return;
    for (re int i = head[now]; i; i = edge[i].next)
    {
        re int to = edge[i].to;
        for (re int j = 0; j < tot; ++j)
        {
            dp[to][j] = dp[now][j] + val[to];
        }
        dfs(to, tot - 1);
        for (re int j = 1; j <= tot; ++j)
        {
            dp[now][j] = max(dp[now][j], dp[to][j-1]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        int fa;
        cin >> fa >> val[i];
        if (fa)
            make_edge(fa, i);
        else
            make_edge(0, i);
    }
    dfs(0, m);
    cout << dp[0][m];
    return 0;
}