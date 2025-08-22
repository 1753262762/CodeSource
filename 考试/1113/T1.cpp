#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int book[maxn];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    for (int i = 1; i <= 5; ++i)
    {
        int tmp;
        cin >> tmp;
        book[tmp]++;
    }
    sort(book, book + 100, cmp);
    if (book[0] == 3 and book[1] == 2)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}