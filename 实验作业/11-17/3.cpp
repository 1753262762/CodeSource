#include <stdio.h> /* sy7-3.c */
#define M 5
#define N 5
main()
{
    int s[M], i, j, min;
    int a[M][N], (*p)[N] = a;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            scanf("%d", p[i] + j);
    for (i = 0; i < M; i++)
    {
        s[i] = p[i][0];
        for (j = 1; j < N; j++)
            if (s[i] < p[i][j])
                s[i] = p[i][j];
    }
    min = s[0];
    for (i = 1; i < M; i++)
        if (min > s[i])
            min = s[i];
    printf("Min=%d\n", min);
}
