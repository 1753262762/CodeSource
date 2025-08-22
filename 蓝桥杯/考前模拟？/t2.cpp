#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 2025 + 5;
const int maxDep = 20;
bool book[maxn];
int x[maxn];
int ansCnt;
void dfs(int dep)
{
    if (dep > maxDep)
    {
        // for (re int i = 1; i < dep; ++i)
        //     cout << x[i] << " ";
        // cout << endl;
        ansCnt++;
        return;
    }
    for (re int i = 1; i <= maxDep; ++i)
    {
        if (!book[i])
        {
            int flag = 1;
            for (re int j = 1; j <= dep; ++j)
            {
                if (x[j] * i > j * dep + 2025)
                {
                    flag = 0;
                    break;
                }
            }
            if (!flag)
                break;
            book[i] = 1;
            x[dep] = i;
            dfs(dep + 1);
            x[dep] = 0;
            book[i] = 0;
        }
    }
}
int main()
{
    dfs(1);
    cout << ansCnt << endl;
    return 0;
}