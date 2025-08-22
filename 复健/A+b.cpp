#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 5e2 + 10;

void add(char *a, char *b)
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

    if (len1 < len2)
    {
        swap(a, b);
        swap(len1, len2);
    }
    char res[maxn] = {0};
    char cnt = 0, carry = 0;

    for (re int i = 1; i <= len1; ++i)
    {
        int sum = a[len1 - i] + (len2 - i >= 0 ? b[len2 - i] : 0) + carry;
        carry = sum / 10;
        res[cnt++] = (sum % 10) + '0';
    }

    if (carry)
        res[cnt++] = carry + '0';

    for (re int i = cnt - 1; i >= 0; --i)
    {
        cout << res[i];
    }
    cout << endl;
}

char s1[maxn], s2[maxn];

int main()
{
    cin >> s1 >> s2;
    add(s1, s2);
    return 0;
}
