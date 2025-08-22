#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 10086 + 10;
void sovle(char *a, char *b)
{
    int len1 = strlen(a), len2 = strlen(b);
    for (re int i = 0; i < len1; ++i)
    {
        a[i] -= '0';
    }
    for (re int i = 0; i < len2; ++i)
    {
        b[i] -= '0';
    }
    int max_len = max(len1, len2);
    char res[maxn] = {0};
    int cnt = 0, carry = 0;
    for (re int i = 1; i <= max_len; ++i)
    {
        int sum = (len1 - i >= 0 ? a[len1 - i] : 0) - (len2 - i >= 0 ? a[len2 - i] : 0);
        }
}
char s1[maxn], s2[maxn];
int main()
{
    cin >> s1 >> s2;
    sovle(s1, s2);
    return 0;
}