#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
int a[maxn], n = 51;
int solve()
{
    int sum = 0;
    for (int i = 1; i <= 51; i++)
    {
        for (int j = i + 1; j <= 51; j++)
        {
            if (a[j] < a[i])
            {
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }
    int cs = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            for (int i2 = 1; i2 <= n; ++i2)
            {
                for (int j2 = i2 + 1; j2 <= n; ++j2)
                {
                    ++cs;
                    swap(a[i], a[j]), swap(a[i2], a[j2]);
                    sum += solve();
                    swap(a[i], a[j]), swap(a[i2], a[j2]);
                }
            }
        }
    }
    printf("%.2f", 1.0 * sum / cs);
    return 0;
}