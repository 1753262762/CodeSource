#include <iostream>
#include <string>
using namespace std;

string findNextNaturalNumber(string S)
{
    int n = S.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (S[i] != '9')
        {
            S[i]++;
            for (int j = i + 1; j < n; ++j)
            {
                S[j] = '0';
            }
            return S;
        }
    }
    return S + "0";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        cout << findNextNaturalNumber(S) << endl;
    }
    return 0;
}
