#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
const int Inf = 1e9 + 5;
#define re register
int x[maxn];
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
    // freopen("a.in", "r", stdin);
    int m = read();
    while (m--)
    {
        int n = read();
        for (re int i = 1; i <= n; ++i)
        {
            x[i] = read();
        }
        for (re int j = 1; j < n; ++j)
        {
            int Min = Inf, Max = -Inf, Mmax = 0;
            int Min_id = 0, Max_id = 0, Mmax_id = 0;
            for (re int i = 1; i <= n; ++i)
            {
                if (x[i] == 0)
                    continue;
                if (Min > x[i])
                {
                    Min = x[i];
                    Min_id = i;
                }
                if (Max <= x[i])
                {
                    Mmax = Max;
                    Mmax_id = Max_id;
                    Max = x[i];
                    Max_id = i;
                }
                else if (x[i] >= Mmax and x[i] <= Max)
                {
                    Mmax = x[i];
                    Mmax_id = i;
                }
            }
            x[Mmax_id] = 0;
            x[Min_id] = (Min + Mmax) / 2;
        }
        int sum = 0;
        for (re int i = 1; i <= n; ++i)
        {
            sum += x[i];
        }
        cout << sum / 2 << endl;
    }
    return 0;
}