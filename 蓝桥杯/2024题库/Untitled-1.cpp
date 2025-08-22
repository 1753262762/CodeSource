#include <iostream>
using namespace std;
int x[55];
int solve()
{
    int sum = 0;
    for (int i = 1; i <= 51; i++)
    {
        for (int j = i + 1; j <= 51; j++)
        {
            if (x[j] < x[i])
            {
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    for (int i = 1; i <= 51; i++)
    {
        x[i] = i;
    }
    int cnt = 0, sum = 0;
    for (int a = 1; a <= 51; a++)
    {
        for (int b = a + 1; b <= 51; b++)
        {
            for (int c = 1; c <= 51; c++)
            {
                for (int d = c + 1; d <= 51; d++)
                {
                    cnt++;
                    swap(x[a], x[b]);
                    swap(x[c], x[d]);
                    sum += solve();
                    swap(x[c], x[d]);
                    swap(x[a], x[b]);
                }
            }
        }
    }
    cout << sum << endl;
    printf("%.2f", 1.0 * sum / cnt);
    return 0;
}