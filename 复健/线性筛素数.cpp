#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e8 + 2006;
#define re register
int book[maxn], prime[maxn], cnt;
int tmpn, tmpq;
void solve()
{
    for (re int i = 2; i*i <= tmpn; i++)
    {
        for (re int j = 2; j <= i; j++)
        {
            book[i * j] = 1;
        }
    }
    for (re int i = 2; i <= tmpn; i++)
    {
        if (book[i] == 0)
        {
            prime[++cnt] = i;
        }
    }
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
int main()
{
    tmpn = read(),tmpq = read();
    solve();
    for (re int i = 1; i <= tmpq; i++)
    {
        printf("%d\n",prime[read()]);
    }
    return 0;
}