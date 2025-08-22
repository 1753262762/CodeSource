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
    for (re int i = 1; i <= 50; ++i)
    {
        if (2024 % i == 0)
        {
            if (is_prime(i))
            {
                cout << i << endl;
            }
        }
    }

    return 0;
}