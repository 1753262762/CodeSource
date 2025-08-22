#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 5e5 + 10;
const int INF = 2147483647;
struct node
{
    int to, next;
    long long dis;
} edge[maxn << 1];
int head[maxn << 1], cnt;
void make_edge(int from, int to, long long dis)
{
    edge[++cnt].next = head[from];
    edge[cnt].dis = dis;
    edge[cnt].to = to;
    head[from] = cnt;
}
long long dis[maxn];
int main()
{
    freopen("b.in", "r", stdin);
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
    for (re int i = 1; i <= n - 1; ++i)
    {
        bool has_Update = 0;
        for (re int j = 1; j <= n; ++j)
        {
            for (re int k = head[j]; k; k = edge[k].next)
            {
                if (dis[edge[k].to] > dis[j] + edge[k].dis)
                {
                    dis[edge[k].to] = dis[j] + edge[k].dis;
                    has_Update = 1;
                }
            }
        }
        if (!has_Update)
        {
            break;
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        cout << dis[i] << ' ';
    }
    return 0;
}