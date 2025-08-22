#include <bits/stdc++.h>
using namespace std;
const int maxn = 26 + 5;
int x[maxn];
int book[maxn];
char ss[1000 + 10];
int main()
{
    cin >> ss;
    for (int i = 1; i <= 26; ++i)
    {
        cin >> x[i];
    }
    int len = strlen(ss);
    for (int i = 0; i < len; ++i)
    {
        book[ss[i] - 'a' + 1]++;
    }
    int ans = 0;
    for (int i = 1; i <= 25; ++i)
    {
        cout << book[i] << ' ';
        ans += book[i] * x[i];
    }
    cout << book[26] << endl;
    ans += book[26] * x[26];
    cout << ans;
    return 0;
}