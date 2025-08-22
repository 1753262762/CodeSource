#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t1, t2, opt;
    cin >> t1 >> opt >> t2;
    if (t1 > 35 and opt == 1 and t2 >= 33)
    {
        cout << "Bu Tie" << endl;
        cout << t1;
    }
    else if (t1 > 35 and t2 >= 33)
    {
        cout << "Shi Nei" << endl;
        cout << t1;
    }
    else if (opt == 1)
    {
        if (t1 <= 35)
        {
            cout << "Bu Re" << endl;
            cout << t2;
        }
        else if (t2 < 33)
        {
            cout << "Bu Re" << endl;
            cout << t2;
        }
    }
    else if (opt == 0 and t2 < 33)
    {
        cout << "Shu shi" << endl;
        cout << t2;
    }
    else if (t1 <= 35)
    {
        cout << "Shu shi" << endl;
        cout << t2;
    }
    return 0;
}