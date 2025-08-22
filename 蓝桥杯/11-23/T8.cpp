#include <bits/stdc++.h>
using namespace std;
char s1[1000 + 10];
char s2[10] = "LANQIAO";
int len1, len2;
#define re register
void search(int dep, int now)
{
    if (dep >= 7)
    {
        cout << "YES" << endl;
        exit(0);
    }
    if (now >= len1)
    {
        return;
    }
    for (re int i = now; i <= len1; ++i)
    {
        if (s2[dep] == s1[i])
        {
            search(dep + 1, i);
        }
    }
}
int main()
{
    cin >> s1;
    len1 = strlen(s1), len2 = strlen(s2);
    search(0, 0);
    cout << "NO" << endl;
    return 0;
}