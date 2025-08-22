#include <stdio.h> /* sy7-4.c */
#define M 4
#define N 5
main()
{
    int a[M][N], *p[M] = {a[0], a[1], a[2], a[3]}, sum = 0, i, j;
    printf("输º?入¨?二t维?数ºy组Á¨¦:êo\n");
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &p[i][j]);
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (i == 0 || j == 0 || i == M - 1 || j == N - 1)
                sum += p[i][j];
    printf("sum=%d\n", sum);
}
