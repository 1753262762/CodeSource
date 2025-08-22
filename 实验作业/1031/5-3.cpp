#include <bits/stdc++.h>
using namespace std;
int a[11] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
int main()
{
    printf("input a number");
    int k;
    scanf("%d", &k);
    for (int i = 9; i >= 0; --i)
    {
        if (k >= a[i])
        {
            a[i + 1] = a[i];
            if (i == 0)
                a[i] = k;
        }
        else
        {
            a[i + 1] = k;
            break;
        }
    }
    for (int i = 0; i < 11; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}