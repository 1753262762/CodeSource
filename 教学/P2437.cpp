#include <stdio.h>
const int maxn = 1000 + 5;
const int max_len = 1000 + 5;
int a[maxn][max_len];

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);

    a[1][1] = 1;
    a[2][1] = 1;

    for (int i = 3; i <= (n - m + 1); i++)
    {
        for (int j = 1; j <= max_len; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 2][j];
        }
        for (int j = 1; j <= max_len; j++)
        {
            if (a[i][j] >= 10)
            {
                a[i][j + 1] += 1;
                a[i][j] -= 10;
            }
        }
    }
    int pd = 0;
    for (int j = max_len; j >= 1; j--)
    {
        if (a[(n - m + 1)][j] != 0)
        {
            pd = 1;
        }
        if (pd != 0)
            printf("%d", a[(n - m + 1)][j]);
    }
    return 0;
}