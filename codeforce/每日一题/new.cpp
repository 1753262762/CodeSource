#include <bits/stdc++.h>
using namespace std;

const int maxn = 20 + 5;
#define re register
int a[maxn];
int n, k;
bool if_prime(int x)
{
    if (x == 1)
        return 0;
    if (x == 2)
        return 1;
    for (re int i = 2; i * i <= x; ++i)
    {
        if (x % i != 0)
        {
            return 0;
        }
    }
    return 1;
}
int ans = 0;
void dfs(int dep, int now, int sum)
{
    if (dep == k)
    {
        ans += if_prime(sum);
    }
    if (now >= n)
        return;
    for (re int i = now + 1; i <= n; ++i)
    {
        dfs(dep + 1, i, sum + a[i]);
    }
}
int main()
{
    cin >> n >> k;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}