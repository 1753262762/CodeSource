#include <stdio.h> /* sy6-4.c */
#define M 4
#define N 5
main()
{
    int a[M][N], i, j, s = 0;
    printf("input matrix A:\n");
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (i == 0 || j == 0 || i == M - 1 || j == N - 1)
                s += a[i][j];
    printf("sum=%d\n", s);
    return 0;
}
