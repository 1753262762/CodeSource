#include <stdio.h>
int main()
{
    int year = 0;
    scanf("%d", &year);
    if (year % 4 != 0)
    {
        printf("NO\n");
    }
    if (year % 4 == 0 && year % 100 != 0)
    {
        printf("YES\n");
    }
    if (year % 100 == 0 && year % 400 != 0)
    {
        printf("NO\n");
    }
    if (year % 400 == 0 && year % 3200 != 0)
    {
        printf("YES\n");
    }
    if (year % 3200 == 0 && year % 172800 != 0)
    {
        printf("NO\n");
    }
    if (year % 172800 == 0)
    {
        printf("YES\n");
    }

    return 0;
}