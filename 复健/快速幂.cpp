#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

ull pow(ull a, ull b, ull p)
{
    if (b == 1)
        return a % p;
    ull tmp = pow(a, b / 2, p) % p;
    return b % 2 == 0 ? (ull)(tmp % p * tmp % p) % p : (ull)(tmp % p * tmp % p * a % p) % p;
}

int main()
{
    ull tmpa, tmpb, tmpp;
    cin >> tmpa >> tmpb >> tmpp;
    printf("%lld^%d mod %lld=%lld", tmpa, tmpb, tmpp, pow(tmpa, tmpb, tmpp));
    return 0;
}