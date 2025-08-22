#include <bits/stdc++.h>
using namespace std;

#define re register
const int Maxn = 5e5 + 10;

int numElements, numQueries;
int treeArray[Maxn];

inline int lowbit(int value)
{
    return value & -value;
}

int sum(int index)
{
    int result = 0;
    while (index > 0)
    {
        result += treeArray[index];
        index -= lowbit(index);
    }
    return result;
}

int querySum(int left, int right)
{
    return sum(right) - sum(left - 1);
}

void add(int index, int value)
{
    while (index <= numElements)
    {
        treeArray[index] += value;
        index += lowbit(index);
    }
}

inline int read()
{
    int result = 0, sign = 1;
    char character = getchar();
    while (character < '0' || character > '9')
    {
        if (character == '-')
            sign = -1;
        character = getchar();
    }
    while (character >= '0' && character <= '9')
    {
        result = result * 10 + character - '0';
        character = getchar();
    }
    return result * sign;
}

int main()
{
    numElements = read(), numQueries = read();
    for (re int i = 1; i <= numElements; ++i)
    {
        add(i, read());
    }
    for (re int i = 1; i <= numQueries; ++i)
    {
        int operation = read();
        if (operation == 1)
        {
            int index = read(), value = read();
            add(index, value);
        }
        else if (operation == 2)
        {
            int left = read(), right = read();
            cout << querySum(left, right) << endl;
        }
    }
    return 0;
}