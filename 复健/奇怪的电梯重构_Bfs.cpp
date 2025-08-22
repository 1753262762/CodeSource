#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200 + 5;
const int INF = 0x3f3f3f;
#define re register

int n, a[Maxn], From, To;
bool Book[Maxn];

struct node
{
    int Dep, Name;
};

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

void Bfs()
{
    queue<node> Q;
    Q.push((node){0, From});
    while (!Q.empty())
    {
        node Now = Q.front();
        if (Now.Name == To)
        {
            cout << Now.Dep << endl;
            exit(0);
        }
        Q.pop();
        int To_up = Now.Name + a[Now.Name], To_down = Now.Name - a[Now.Name];
        if (To_up <= n)
        {
            if (!Book[To_up])
            {
                Book[To_up] = 1;
                Q.push((node){Now.Dep + 1, To_up});
            }
        }
        if (To_down >= 1)
        {
            if (!Book[To_down])
            {
                Book[To_down] = 1;
                Q.push((node){Now.Dep + 1, To_down});
            }
        }
    }
}
int main()
{
    n = read(), From = read(), To = read();
    for (re int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    Bfs();
    cout << "-1" << endl;
    return 0;
}