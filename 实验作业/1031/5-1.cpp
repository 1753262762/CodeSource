#include <stdio.h> // sy5-2.c
#include <stdlib.h>
#include <time.h>
main()
{
    int a[10], i, max, min;
    float aver;
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
        a[i] = rand() % 50 + 1;
    /**********found**********/
    max = min = aver = a[0];
    for (i = 1; i < 10; i++)
    {
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
        /**********found**********/
        aver = aver + a[i];
        printf("%d  ", a[i]);
    }
    aver = aver / 10;
    printf("\nMax=%d  Min=%d  Average=%.2f\n", max, min, aver);
    system("pause");
}
