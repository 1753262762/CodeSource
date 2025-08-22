#include <bits/stdc++.h>
using namespace std;

size_t const_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << const_calls() << " ";
    }
    return 0;
}