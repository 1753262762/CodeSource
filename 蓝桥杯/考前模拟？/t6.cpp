#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
char ss;
int Map[maxn][3], cnt1, cnt2;
int main()
{
    freopen("a.in", "r", stdin);
    while ((ss = getchar()) != '\n')
    {
        if (ss == '.')
            Map[++cnt1][1] = 0;
        else if (ss == '#')
            Map[++cnt1][1] = 1;
    }
    while ((ss = getchar()) != EOF)
    {
        if (ss == '.')
            Map[++cnt2][2] = 0;
        else if (ss == '#')
            Map[++cnt2][2] = 1;
    }
    int l = 1, r = cnt1;
    while (1)
    {
        if (Map[l][1] or Map[l][2])
            break;
        else
            ++l;
    }
    while (1)
    {
        if (Map[r][1] or Map[r][2])
            break;
        else
            --r;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = l; i <= r; ++i)
    {
        if (!Map[i][1])
            sum1++;
        if (!Map[i][2])
            sum2++;
    }
    cout << min(sum1, sum2) << endl;
    return 0;
}