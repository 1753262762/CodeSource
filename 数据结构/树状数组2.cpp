#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 5e5 + 10;

int n, m;
int c[Maxn], a[Maxn];

inline int lowbit(int x)
{
    return x & -x;
}

int sum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
int Query_sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}
void add(int x, int k)
{
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
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
    n = read(), m = read();
    for (re int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    add(1, a[1]);
    for (re int i = 2; i <= n; ++i)
    {
        add(i, a[i] - a[i - 1]);
    }
    for (re int i = 1; i <= m; ++i)
    {
        int ope = read();
        if (ope == 1)
        {
            int l = read(), r = read(), x = read();
            add(l, x);
            add(r + 1, -x);
        }
        else if (ope == 2)
        {
            int x = read();
            cout << Query_sum(1, x) << endl;
        }
    }
    return 0;
}