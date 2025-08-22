#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (2024 % n)
    {
        cout << 2024 / n + 1 << endl;
    }
    else
        cout << 2024 / n << endl;
    return 0;
}