#include <bits/stdc++.h>
using namespace std;
static inline bool if_is_run_year(int x)
{
    if (x % 4 == 0 && x % 100 != 0)
        return true;
    else if (x % 400 == 0 && x % 3200 != 0)
        return true;
    else if (x % 172800 == 0)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    cout << (if_is_run_year(n) ? "Yes" : "No");
    return 0;
}