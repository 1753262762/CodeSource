#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
#define re register
struct node
{
    int l, r;
} a[maxn];
bool cmp(node x, node y)
{
    return x.l < y.l;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        for (re int i = 1; i <= n; ++i)
        {
            cin >> a[i].l >> a[i].r;
        }
        if (a[1].l >= s)
        {
            cout << "YES" << endl;
            continue;
        }
        if (m - a[n].r >= s)
        {
            cout << "YES" << endl;
            continue;
        }
        bool flag = 0;
        for (re int i = 2; i <= n; ++i)
        {
            if (a[i].l - a[i - 1].r >= s)
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}