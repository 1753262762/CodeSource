#include <bits/stdc++.h>
using namespace std;

const int Max_N = 100 + 5;
#define re register

struct node
{
    int to;
    int next;
} edge[Max_N];
int head[Max_N], cnt, Deg[Max_N], N;
void add(int from, int to)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
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
void Solve()
{
    queue<int> Q;
    for (re int i = 1; i <= N; i++)
    {
        if (Deg[i] == 0)
        {
            cout << i << ' ';
            Q.push(i);
        }
    }
    while (!Q.empty())
    {
        int Now = Q.front();
        Q.pop();
        for (re int i = head[Now]; i != 0; i = edge[i].next)
        {
            Deg[edge[i].to]--;
            if (Deg[edge[i].to] == 0)
            {
                cout << edge[i].to << ' ';
                Q.push(edge[i].to);
            }
        }
    }
} 
int main()
{
    N = read();
    for (re int i = 1; i <= N; ++i)
    {
        while (1)
        {
            int Tmp = read();
            if (Tmp == 0)
            {
                break;
            }
            else
            {
                add(i, Tmp);
                ++Deg[Tmp];
            }
        }
    }
    Solve();
    return 0;
}