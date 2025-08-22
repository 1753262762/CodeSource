#include <stdio.h> /* sy6-3.c */
#include <stdlib.h>
#include <time.h>
main()
{
    char ch, s[21];
    int n = 0, i;
    srand((unsigned)time(NULL));
    ch = 65 + rand() % 26;
    s[n] = ch;
    while (n < 20)
    {
        ch = 65 + rand() % 26;
        for (i = 0; i <= n; i++)
        {
            if (ch == s[i])
                break;
        }
        if (i > n)
        {
            n++;
            s[n] = ch;
        }
    }
    s[n] = '\0';
    puts(s);
    return 0;
}