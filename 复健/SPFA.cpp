#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
const int INF = 2147483647;
#define re register

struct node
{
    int to, next;
    long long dis;
} edge[maxn << 1];
int head[maxn], cnt = 0;
void make_edge(int from, int to, long long dis)
{
    edge[++cnt].next = head[from];
    edge[cnt].dis = dis;
    edge[cnt].to = to;
    head[from] = cnt;
}
long long dis[maxn];
bool vis[maxn];
int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    for (re int i = 1; i <= m; ++i)
    {
        int tmpu, tmpv, tmpw;
        cin >> tmpu >> tmpv >> tmpw;
        make_edge(tmpu, tmpv, tmpw);
    }
    for (re int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop(), vis[now] = 0;
        for (re int i = head[now]; i; i = edge[i].next)
        {
            if (dis[edge[i].to] > dis[now] + edge[i].dis)
            {
                dis[edge[i].to] = dis[now] + edge[i].dis;
                if (!vis[edge[i].to])
                {
                    Q.push(edge[i].to);
                    vis[edge[i].to] = 1;
                }
            }
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        cout << dis[i] << ' ';
    }
    return 0;
}