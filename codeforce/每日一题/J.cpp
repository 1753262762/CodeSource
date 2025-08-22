#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 1000 + 10;

bool vis[maxn];
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

inline bool is_coprime(int a, int b)
{
    return gcd(a, b) == 1;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (re int i = l; i <= r; ++i)
        {
            for (re int j = l; j < i; ++j)
            {
                if (vis[j])
                    continue;
                if (is_coprime(i, j))
                    for (re int k = l; k < j; ++k)
                    {
                        if (vis[i] or vis[j] or vis[k])
                            continue;
                        if (is_coprime(i, k) && is_coprime(j, k))
                        {
                            vis[i] = 1, vis[j] = 1, vis[k] = 1;
                            cout << k << ' ' << j << ' ' << i << endl;
                            ++ans;
                        }
                    }
            }
        }
        cout << ans << endl;
    }
    return 0;
}