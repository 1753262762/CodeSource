#include <bits/stdc++.h>
using namespace std;
int book[256];
char ss[1000 + 10];
int main()
{
    cin >> ss;
    int len = strlen(ss);
    for (int i = 0; i < len; ++i)
    {
        book[ss[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i <= 255; ++i)
    {
        if (i != 8)
        {
            ans += book[i] ? 1 : 0;
        }
    }
    cout << ans << endl;
    return 0;
}