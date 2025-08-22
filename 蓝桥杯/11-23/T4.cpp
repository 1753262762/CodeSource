#include <bits/stdc++.h>
using namespace std;
int ans = 0x3f3f3f;
int MAX__(int x)
{
    int res = 0;
    for (int i = 1; i <= 4; ++i)
    {
        res = max(x % 10, res);
        x /= 10;
    }
    return res;
}
int book[2024];
void dfs(int x, int dep)
{
    // cout << x << ' ' << dep << endl;
    if (x == 2024)
    {
        ans = min(dep, ans);
    }
    if (dep >= ans)
        return;
    if (book[x] != 0 and dep >= book[x])
        return;
    if (x > 2024)
        return;
    book[x] = dep;
    dfs(x * 2, dep + 10);
    dfs(x + 1, dep + 1);
    dfs(x + MAX__(x), dep + 3);
}
int main()
{
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}