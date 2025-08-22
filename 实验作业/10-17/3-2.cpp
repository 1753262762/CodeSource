#include <bits/stdc++.h>
using namespace std;
int sovle(int x)
{
    if (x < 1000)
        return x;
    else if (x < 2000)
        return 0.9 * x;
    else if (x < 3000)
        return 0.8 * x;
    else
        return 0.7 * x;
}
int main()
{
    int x;
    cin >> x;
    cout << "x:" << x << ' ' << "y:" << sovle(x) << endl;
    return 0;
}