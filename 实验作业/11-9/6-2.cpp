#include <stdio.h> /* sy6-2.c */
main()
{
    int a[4][5], i, j, k, max;
    printf("input matrix A:\n");
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < 4; i++)
    {
        k = 0;
        max = a[i][0];
        for (j = 1; j < 5; j++)
            if (max < a[i][j])
            {
                max = a[i][j];
                k = j;
            }
        for (j = 0; j < 4; j++)
            if (max > a[j][k])
                break;
        if (j >= 4)
            printf("a[%d,%d] is a saddle point\n", i, k);
    }
    return 0;
}