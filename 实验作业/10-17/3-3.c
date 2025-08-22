#include <stdio.h>
int main()
{
    char c1, c2, c3, c4;
    int n;
    long int x;
    c1 = c2 = c3 = c4 = ' ';
    scanf("%ld", &x);
    if (x >= 1000)
        n = 4;
    else if (x >= 100)
        n = 3;
    else if (x >= 10)
        n = 2;
    else
        n = 1;
    switch (n)
    {
    case 4:
        c4 = x % 10 + '0';
        x = x / 10;
    case 3:
        c3 = x % 10 + '0';
        x = x / 10;
    case 2:
        c2 = x % 10 + '0';
        x = x / 10;
    case 1:
        c1 = x % 10 + '0';
        x = x / 10;
    }
    printf("n=%d\n", n);
    printf("%c%c%c%c\n", c1, c2, c3, c4);
    printf("%c%c%c%c\n", c4, c3, c2, c1);
    return 0;
}