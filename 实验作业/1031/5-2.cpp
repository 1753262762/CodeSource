#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f;
#define re register
int main()
{
    int a[10], Max = -INF, Min = INF;
    double ave;
    srand((unsigned)time(NULL));
    for (re int i = 1; i <= 10; ++i)
    {
        a[i] = rand() % 50 + 1;
        cout << a[i] << ' ';
    }
    cout << endl;
    for (re int i = 1; i <= 10; ++i)
    {
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
        ave += a[i];
    }
    ave /= 10;
    cout << "Max:" << Max << " Min:" << Min << " ave:" << ave << endl;
    return 0;
}