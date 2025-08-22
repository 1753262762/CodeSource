#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200 + 5;
const int INF = 0x3f3f3f;
#define re register

int n, a[Maxn], From, To;
int Limit = 1;
bool If_ans = 0;
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

bool dfs(int Dep, int Now)
{
    if (Dep > Limit)
        return 0;
    if (Now == To)
    {
        If_ans = 1;
        return 1;
    }
    if (Now + a[Now] <= n)
        dfs(Dep + 1, Now + a[Now]);
    if (Now - a[Now] >= 1)
        dfs(Dep + 1, Now - a[Now]);
    return 0;
}

int main()
{
    n = read(), From = read(), To = read();
    for (re int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    while (1)
    {
        dfs(0, From);
        if (If_ans)
            break;
        Limit++;
    }
    cout << Limit << endl;
    return 0;
}