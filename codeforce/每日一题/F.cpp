#include <bits/stdc++.h>
using namespace std;
#define re register
const int maxn = 2e5 + 10;
int a[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << -1 << endl;
            continue;
        }
        else if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            int cnt = n;
            int head = 1, end = n;
            while (1)
            {
                a[head] = n;
                --n;
                ++head;
                if (!n)
                {
                    break;
                }
                a[end] = n;
                --n;
                --end;
            }
            for (re int i = 1; i <= cnt; ++i)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
