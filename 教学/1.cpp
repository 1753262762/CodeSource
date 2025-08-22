#include <bits/stdc++.h>
using namespace std;
#define re register
int main()
{
    int n = 7;
    for (re int i = 1; i <= n; i++)
    {
        for (re int j = 1; j <= n - i; ++j)
        {
            cout << ' ';
        }
        for (re int j = 1; j <= i; j++)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}