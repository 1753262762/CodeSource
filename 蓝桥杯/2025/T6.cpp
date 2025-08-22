#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node
{
    int to, next;
} edge[maxn];
int head[maxn], cnt = 0;
void add(int u, int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int val[maxn];
int cur;
int book[maxn];
void dfs(int u, int dep)
{
    if (dep >= cur)
        return;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!book[v])
        {
            book[v] = 1;
            dfs(v, dep + 1);
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    cur = 2 * k;
    book[1] = 1;
    dfs(1, 0);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (book[i])
        {
            sum += val[i];
        }
    }
    cout << sum << endl;
    return 0;
}