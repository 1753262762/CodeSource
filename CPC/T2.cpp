#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 5e4 + 10;
const int INF = 0x3f3f3f3f;
int n, k;
int x[maxn];
int main()
{
    scanf("%d%d", &n, &k);
    for (re int i = 1; i <= n; ++i)
    {
        scanf("%d", &x[i]);
    }
    priority_queue<int> q;
    for (re int l = 1; l <= n; ++l)
    {
        int TmpMax = 0, TmpMin = INF;
        for (re int r = l; r <= n; ++r)
        {
            TmpMax = max(TmpMax, x[r]), TmpMin = min(TmpMin, x[r]);
            q.push((TmpMax * TmpMin * (r - l + 1)));
            // cout << TmpMax * TmpMin * (r - l + 1) << endl;
        }
    }
    for (re int i = 1; i < k; ++i)
    {
        q.pop();
    }
    cout << q.top() << endl;
    return 0;
}