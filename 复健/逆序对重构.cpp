#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 5e5 + 10;

int a[maxn], tmp[maxn];
long long ans;
void merge_sort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid and j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (re int i = l; i <= r; ++i)
        a[i] = tmp[i];
}
inline int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int main()
{
    int n = read();
    for (re int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}