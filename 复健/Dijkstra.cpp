#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 5e5;
const int INF = 2147483647;
struct node
{
    int to, next, dis;
} edge[maxn << 1];
int head[maxn], cnt = 0;
bool vis[maxn];
void make_edge(int from, int to, int dis)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    edge[cnt].dis = dis;
    head[from] = cnt;
}
void add(int from, int to, int dis)
{
    make_edge(from, to, dis);
    make_edge(to, from, dis);
}
int dis[maxn];
int main()
{
    freopen("a.in", "r", stdin);
    memset(vis, 0, sizeof(vis));
    // memset(dis, 0x3f, sizeof(dis));
    int n, m, s;
    cin >> n >> m >> s;
    for (re int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
    }
    for (re int i = 1; i <= m; ++i)
    {
        int tmpu, tmpv, tmpw;
        cin >> tmpu >> tmpv >> tmpw;
        make_edge(tmpu, tmpv, tmpw);
    }
    dis[s] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push(make_pair(0, s));
    while (!Q.empty())
    {
        int Dis = Q.top().first, id = Q.top().second;
        Q.pop();
        if (vis[id])
            continue;
        vis[id] = 1;
        for (re int i = head[id]; i; i = edge[i].next)
        {
            if (dis[edge[i].to] > dis[id] + edge[i].dis)
            {
                dis[edge[i].to] = dis[id] + edge[i].dis;
                Q.push(make_pair(-dis[edge[i].to], edge[i].to));
            }
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        cout << dis[i] << ' ';
    }
    return 0;
}