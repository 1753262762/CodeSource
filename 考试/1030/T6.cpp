#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string ss;
    cin >> ss;
    for (int i = 0; i < ss.length(); ++i)
    {
        if (ss[i] == '-')
        {
            char head = ss[i - 1];
            char end = ss[i + 1];
            if (head >= '0' && head <= '9')
            {
                if (end >= '0' && end <= '9')
                {
                    if (head >= end)
                    {
                        cout << '-';
                    }
                    else if (head + 1 == end)
                    {
                        continue;
                    }
                    else
                    {
                        if (p3 == 2)
                        {
                            for (int i1 = end - 1; i1 >= head + 1; --i1)
                            {
                                for (int j = 1; j <= p2; ++j)
                                {
                                    if (p1 == 3)
                                        cout << '*';
                                    else
                                        cout << char(i1);
                                }
                            }
                        }
                        else
                        {
                            for (int i1 = head + 1; i1 <= end - 1; ++i1)
                            {
                                for (int j = 1; j <= p2; ++j)
                                {
                                    if (p1 == 3)
                                        cout << '*';
                                    else
                                        cout << char(i1);
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout << ss[i];
                    continue;
                }
            }
            else if (head >= 'a' && head <= 'z')
            {
                if (end >= 'a' && end <= 'z')
                {
                    if (head >= end)
                    {
                        cout << '-';
                    }
                    else if (head + 1 == end)
                    {
                        continue;
                    }
                    else
                    {
                        if (p3 == 2)
                        {
                            for (int i1 = end - 1; i1 >= head + 1; --i1)
                            {
                                for (int j = 1; j <= p2; ++j)
                                {
                                    if (p1 == 2)
                                    {
                                        cout << char(toupper(char(i1)));
                                    }
                                    else if (p1 == 3)
                                    {
                                        cout << '*';
                                    }
                                    else
                                        cout << char(i1);
                                }
                            }
                        }
                        else
                        {
                            for (int i1 = head + 1; i1 <= end - 1; ++i1)
                            {
                                for (int j = 1; j <= p2; ++j)
                                {
                                    if (p1 == 2)
                                    {
                                        cout << char(toupper(char(i1)));
                                    }
                                    else if (p1 == 3)
                                    {
                                        cout << '*';
                                    }
                                    else
                                        cout << char(i1);
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout << ss[i];
                    continue;
                }
            }
            else
                cout << ss[i];
        }
        else
        {
            cout << ss[i];
        }
    }
    return 0;
}