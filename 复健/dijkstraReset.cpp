#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
const int MAXM = 5e5 + 10;
const int INF = 0x3f3f3f3f;
#define re register

struct Node
{
    int to, next, dis;
} edge[MAXM << 1];
int head[MAXM], cnt = 0;
inline void MakeEdge(int from, int to, int dis)
{
    edge[++cnt] = (Node){to, head[from], dis};
    head[from] = cnt;
}
inline void AddEdge(int from, int to, int dis)
{
    MakeEdge(from, to, dis);
    MakeEdge(to, from, dis);
}

inline int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int n, m, s, dis[MAXN];
bool vis[MAXN];
inline void init()
{
    n = read(), m = read(), s = read();
    for (re int i = 1; i <= m; ++i)
    {
        int u = read(), v = read(), w = read();
        AddEdge(u, v, w);
    }
}
void dijkstra(int s)
{
    // memset(dis, 0x3f, sizeof(dis));
    for (re int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
    }
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push(make_pair(0, s));
    while (!Q.empty())
    {
        int id = Q.top().second;
        Q.pop();
        if (vis[id])
            continue;
        vis[id] = 1;
        for (re int i = head[id]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            if (dis[to] > dis[id] + edge[i].dis)
            {
                dis[to] = dis[id] + edge[i].dis;
                Q.push(make_pair(-dis[to], to));
            }
        }
    }
}
inline void output()
{
    for (re int i = 1; i <= n; ++i)
    {
        printf("%d ", dis[i]);
    }
}
int main()
{
    freopen("a.in", "r", stdin);
    init();
    dijkstra(s);
    output();
    return 0;
}