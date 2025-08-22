#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main()
{
    char ss[maxn];
    cin >> ss;
    int n = strlen(ss);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        a[ss[i] - 'a' + 1]++;
    }
    for (int i = 26; i >= 1; --i)
    {
        if (a[i])
        {
            for (int j = 1; j <= a[i]; ++j)
            {
                cout << char(i + 'a' - 1);
            }
            return 0;
        }
    }
    return 0;
}