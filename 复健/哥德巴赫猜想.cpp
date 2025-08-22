#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 1e4 + 5;

bool Book[Maxn];

int Prime[Maxn], cnt = 0, n;

void Get_prime()
{
    for (re int i = 2; i <= n; ++i)
    {
        if (!Book[i])
            Prime[++cnt] = i;
        for (re int j = 1; Prime[j] * i <= n and j <= cnt; ++j)
        {
            Book[Prime[j] * i] = 1;
            if (i % Prime[j] == 0)
                break;
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
void Goldbach(int x)
{
    for (re int i = 1; i <= cnt; ++i)
    {
        for (re int j = i; j <= cnt; ++j)
        {
            if (Prime[i] + Prime[j] == x)
            {
                cout << x << '=' << Prime[i] << '+' << Prime[j] << endl;
                return;
            }
        }
    }
    cout << "error" << endl;
}
int main()
{
    n = read();
    Get_prime();
    for (re int i = 4; i <= n; i += 2)
    {
        Goldbach(i);
    }
    return 0;
}