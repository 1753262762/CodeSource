#include <bits/stdc++.h>
using namespace std;

const int maxn = 65 + 5;
#define re register
int a[maxn], sum;
int n;
bool if_use[maxn];
int cnt_num;
double st;
bool dfs(int height, int num, int now, int id)
{
    if (cnt_num < num)
        return 0;
    if (num == 0)
    {
        cout << height << endl;
        exit(0);
        // return 1;
    }
    for (re int i = id + 1; i <= n; ++i)
    {
        if (if_use[i])
            continue;
        if (a[i] == now)
        {
            if_use[i] = 1;
            --cnt_num;
            dfs(height, num - 1, height, 0);
            ++cnt_num;
            if_use[i] = 0;
            break;
        }
        if (a[i] < now)
        {
            if_use[i] = 1;
            --cnt_num;
            dfs(height, num, now - a[i], i);
            ++cnt_num;
            if_use[i] = 0;
            if (num == height)
            {
                break;
            }
            while (i < n and a[i] == a[i + 1])
            {
                ++i;
            }
        }
        if (i == 1)
            return 0;
    }
    return 0;
}
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("b.in", "r", stdin);
    cin >> n;
    cnt_num = n;
    for (re int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp > 50)
        {
            --n;
            continue;
        }
        a[i] = tmp;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (re int i = a[1]; i <= sum; ++i)
    {
        if (sum % i != 0)
            continue;
        // cout << i << endl;
        dfs(i, sum / i, i, 0);
    }
    return 0;
}