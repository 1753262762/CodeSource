#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn] = {0, 2, 4, 3, 1, 5};
int n = 5;
int main()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
    冒泡排序
    cout << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }
    return 0;
}