#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << min(x, y) << ' ' << max(0, x + y - n);
    return 0;
}