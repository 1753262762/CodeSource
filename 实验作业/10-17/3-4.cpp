#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0)
    {
        cout << -c / b << endl;
    }
    else
    {
        int d = b * b - 4 * a * c;
        if (d == 0)
        {
            cout << (-b) / (2 * a) << ' ' << (-b) / (2 * a) << endl;
        }
        else if (d < 0)
        {
            cout << "共轭复根" << endl;
        }
        else
        {
            cout << (-b + sqrt(d)) / (2 * a) << ' ' << (-b - sqrt(d)) / (2 * a) << endl;
        }
    }
    return 0;
}