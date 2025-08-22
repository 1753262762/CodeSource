#include <bits/stdc++.h>
using namespace std;
const int N = 20;
#define re register
int a[N];
int main()
{
    int n = N;
    srand((unsigned)time(NULL));
    cout << "Original date:" << endl;
    for (re int i = 1; i <= N; ++i)
    {
        a[i] = rand() % 21;
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << "after deleting" << endl;
    for (re int i = 1; i <= n - 1; ++i)
    {
        int j = i + 1;
        while (j < n)
        {
            if (a[i] == a[j])
            {
                --n;
                for (re int k = j; k <= n; ++k)
                {
                    a[k] = a[k + 1];
                }
            }
            else
                ++j;
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}