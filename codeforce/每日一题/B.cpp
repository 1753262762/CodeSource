#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char s1, s2;
        cin >> s1 >> s2;
        cout << (s1 - '0') + (s2 - '0') << endl;
    }
    return 0;
}