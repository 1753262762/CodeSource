#include <bits/stdc++.h>
using namespace std;
#define re register
bool is_prime(int x)
{
    for (re int i = 2; i <= sqrt(x); ++i)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    cout << __lcm(2024, 1024);
    return 0;
}

// 52915264