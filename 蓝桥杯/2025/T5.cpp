#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a1[maxn], a2[maxn];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a1[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a2[i];
    }
    sort(a1, a1 + 1 + n, cmp);
    sort(a2, a2 + 1 + n, cmp);
    int i = 1, j = 1;
    while (j <= n)
    {
        if (a1[i] > a2[j])
            i++;
        j++;
    }
    cout << j - i << endl;
    return 0;
}