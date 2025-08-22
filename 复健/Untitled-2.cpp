#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
using namespace std;
#define re register
const int maxn = 1e5;
void add(char *a, char *b)
{
    int len1 = strlen(a), len2 = strlen(b);
    for (re int i = 0; i < len1; ++i)
    {
        a[i] -= '0';
    }
    for (re int i = 0; i < len2; ++i)
    {
        b[i] -= '0';
    }
    if (len1 < len2)
    {
        swap(a, b);
        swap(len1, len2);
    }
    char res[maxn], cnt = 0, carry = 0;
    for (re int i = len1 - 1; i >= 0; --i)
    {
        int sum = a[i] + b[i] + carry;
        carry = 0;
        if (sum >= 10)
        {
            sum -= 10;
            res[++cnt] = sum;
            carry = 1;
        }
        else
        {
            res[++cnt] = sum;
        }
    }
    if (carry)
        res[++cnt] = 1;
    for (re int i = cnt; i >= 1; --i)
    {
        cout << int(res[i]);
    }
    cout << endl;
}
void test_add()
{
    // Test case 1: Happy path
    char a1[] = "123";
    char b1[] = "456";
    stringstream buffer;
    streambuf *oldCout = cout.rdbuf(buffer.rdbuf());
    add(a1, b1);
    cout.rdbuf(oldCout);
    assert(buffer.str() == "579\n");

    // Test case 2: Edge case - adding zero
    char a2[] = "0";
    char b2[] = "123";
    buffer.str(""); // clear buffer
    add(a2, b2);
    assert(buffer.str() == "123\n");

    // Test case 3: Edge case - both zeros
    char a3[] = "0";
    char b3[] = "0";
    buffer.str(""); // clear buffer
    add(a3, b3);
    assert(buffer.str() == "0\n");

    // Test case 4: Edge case - different lengths
    char a4[] = "99";
    char b4[] = "1";
    buffer.str(""); // clear buffer
    add(a4, b4);
    assert(buffer.str() == "100\n");

    // Test case 5: Edge case - large numbers
    char a5[] = "9999999999999999999999";
    char b5[] = "1";
    buffer.str(""); // clear buffer
    add(a5, b5);
    assert(buffer.str() == "10000000000000000000000\n");
}

int main()
{
    test_add();
    cout << "All tests passed!" << endl;
    return 0;
}