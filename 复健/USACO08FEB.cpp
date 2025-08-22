#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 5e4 + 10;
const int Maxmap = 300 + 10;

int m;

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

struct node
{
    int x, y, Time;
    void input()
    {
        x = read(), y = read(), Time = read();
    }
    void output()
    {
        cout<<x<<' '<<y<<' '<<Time<<endl;
    }
} a[Maxn];
int cnt = 1;
bool cmp(node a, node b)
{
    return a.Time < b.Time;
}
bool Map[Maxmap][Maxmap];
bool Boom[Maxmap][Maxmap];
int to_x[5]={0,0, 0,1,-1};
int to_y[5]={0,1,-1,0, 0};
void Bfs()
{
    queue<node> Q;
    Q.push(node{0, 0, 0});
    while (!Q.empty())
    {
        node Now = Q.front();
        // Now.output();
        Q.pop(); 
        while (a[cnt].Time == Now.Time + 1)
        {
            Map[a[cnt].x][a[cnt].y] = 1;
            ++cnt;
        }
        if(cnt==m+1)
        {
            cout<<Now.Time+1<<endl;
            exit(0);
        }
        for(re int i=1;i<=4;++i)
        {
            if(Now.x+to_x[i]>=0 and Now.y+to_y[i]>= 0)
            {
                if(!Map[Now.x+to_x[i]][Now.y+to_y[i]])
                {
                    Q.push(node{Now.Time+1,Now.x+to_x[i],Now.y+to_y[i]});
                }
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    m = read();
    for (re int i = 1; i <= m; ++i)
    {
        a[i].input();
        // Boom[a[i].x][a[i].y]=1;
    }
    sort(a + 1, a + 1 + m, cmp);
    Bfs();
    cout<<"-1"<<endl;
    return 0;
}