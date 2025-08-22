#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        for (int i = 1; i <= k; ++i)
        {
            int tmpA = (b + c) / 2, tmpB = (a + c) / 2, tmpC = (a + b) / 2;
            if (a == tmpA and b == tmpB and c == tmpC)
                break;
            a = tmpA, b = tmpB, c = tmpC;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}