#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 500 + 10;
const int Inf = 0x3f3f3f3f;

int n, m, From, To;
int value[Maxn];

struct node
{
    int to;
    int next;
    int dis;
} edge[Maxn];
int head[Maxn], cnt;
inline void add(int from, int to, int dis)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    edge[cnt].dis = dis;
    head[from] = cnt;
}
inline void make_edge(int u, int v, int dis)
{
    add(u, v, dis);
    add(v, u, dis);
}

int minDisCnt;
int Dis[Maxn];
int bookWay[Maxn], cntBookWay, cntValue;
int ansBookway[Maxn], ansCntBookWay, ansCntVaule = 0;
void dfs(int u, int cnt)
{
    if (u == To)
    {
        if (Dis[u] == cnt)
        {
            minDisCnt++;
        }
        else
        {
            Dis[u] = cnt;
            minDisCnt = 1;
        }
        return;
    }
    for (re int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (Dis[v] >= cnt + edge[i].dis)
        {
            dfs(v, cnt + edge[i].dis);
        }
    }
}
void dfsBookway(int u, int far)
{
    if (far = minDisCnt)
    {
    }
    for (re int i = head[u]; i; i = edge[i].next)
    {
    }
} // todo
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
int main()
{
    freopen("a.in", "r", stdin);
    n = read(), m = read(), From = read() + 1, To = read() + 1;
    for (re int i = 1; i <= n; ++i)
    {
        value[i] = read();
        Dis[i] = Inf;
    }
    for (re int i = 1; i <= m; i++)
    {
        int u, v, w;
        u = read() + 1, v = read() + 1, w = read();
        add(u, v, w);
    }
    dfs(From, 0);
    cout << minDisCnt << ' ';
    cout << ansCntVaule + value[From] << endl;
    for (re int i = 1; i <= ansCntBookWay; i++)
    {
        cout << ansBookway[i] << " ";
    }
    return 0;
}