#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10;

int a[maxn], b[maxn], dis[maxn];
int suma, sumb;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        sumb += b[i];
    }
    if (suma != sumb)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        dis[i] = b[i] - a[i];
    }
    long long move = 0;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        move += dis[i];
        ans += abs(move);
    }
    cout << ans << endl;

    return 0;
}
