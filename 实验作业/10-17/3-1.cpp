#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 10;
int a[maxn];
int main()
{
    for (re int i = 1; i <= 3; ++i)
    {
        cin >> a[i];
    }
    for (re int i = 1; i <= 3; ++i)
    {
        for (re int j = 1; j <= i; ++j)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (re int i = 1; i <= 3; ++i)
    {
        cout << a[i] << ' ';
    }
    return 0;
}