#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
bool a[maxn], b[maxn];
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] == '*')
        {
            a[i] = 1;
        }
        else
            a[i] = 0;
    }
    for (int i = 0; i < s2.size(); ++i)
    {
        if (s2[i] == '*')
        {
            b[i] = 1;
        }
        else
            b[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < s1.size(); ++i)
    {
        if (a[i] != b[i])
        {
            a[i + 1] = !a[i + 1];
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}