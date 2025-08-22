#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> results = {
        a * b * c,
        a + b * c,
        a + b + c,
        a * b + c,

        (a + b) * c,
        a + (b * c),

        (a + b) + c,
        a + (b + c),

        (a * b) * c,
        a * (b * c),
        (a * b) + c,
        a * (b + c),
    };

    cout << *max_element(results.begin(), results.end()) << endl;

    return 0;
}
