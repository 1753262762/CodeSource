#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int cnt = 0;
    while (a > 0)
    {
        a >>= 1;
        cnt++;
    }
    cout << (1 << (cnt - 1)) << endl;
    return 0;
}