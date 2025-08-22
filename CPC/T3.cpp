#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct node
{
    int l, r, id;
    void Input(int x)
    {
        cin >> l >> r;
        id = x;
    }
} a[maxn];
bool cmp(node a, node b)
{
    if (a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}
int ans[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].Input(i);
    }
    sort(a + 1, a + 1 + n, cmp);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].l <= cnt and a[i].r >= cnt)
        {
            ans[++cnt] = a[i].id;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}