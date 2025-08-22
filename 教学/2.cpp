#include <bits/stdc++.h>
using namespace std;
int a[100100] = {0};
int b[100100] = {0};
int m, n;
int bin_check(int x)
{
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    int minn = 10000000;
    if (l <= m)
        minn = min(minn, abs(a[l] - x));
    if (r >= 1)
        minn = min(minn, abs(a[r] - x));
    return minn;
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + m);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += bin_check(b[i]);
    }
    cout << sum;
    return 0;
}