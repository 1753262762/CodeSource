#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string ss;
        cin >> ss;
        if (ss.size() <= 2)
        {
            cout << "NO" << endl;
            continue;
        }
        if (ss[0] != '1' or ss[1] != '0')
        {
            cout << "NO" << endl;
            continue;
        }
        if (ss.size() == 3 and (ss[2] == '1'))
        {
            cout << "NO" << endl;
            continue;
        }
        if (ss.size() >= 3 and ss[2] == '0')
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
    return 0;
}