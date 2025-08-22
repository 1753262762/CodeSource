#include <stdio.h> /* sy6-1.c */
main()
{
    int a[6][6], i, j, m, n, sum;
    printf("input m,n:");
    scanf("%d%d", &m, &n);
    printf("input array:");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < m; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum = sum + a[i][j];
        printf("sum of row %d : %d\n", i + 1, sum);
    }
    return 0;
}
