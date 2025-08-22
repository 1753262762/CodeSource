#include <bits/stdc++.h>
int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << (a == 0 ? (b & 1 ? "NO" : "YES") : (a & 1 ? "NO" : "YES")) << std::endl;
    }
    return 0;
}