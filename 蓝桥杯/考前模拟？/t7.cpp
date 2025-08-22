#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
struct node
{
    int to, next;
} edge[maxn];
int head[maxn], cnt;
void make_edge(int from, int to)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}
int n;
int val[maxn];
void dfs(int u)
{
    int sum = 0;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        sum += val[v];
    }
}
int main()
{
    freopen("b.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> val[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int from, to;
        cin >> from >> to;
        make_edge(from, to);
    }
    dfs(1);
    return 0;
}