#include <stdio.h> /* sy7-2.c */
#define M 10
main()
{
    int a[M], *p = a, aver = 0;
    int i, j, k, n;
    printf("input n:");
    scanf("%d", &n);
    printf("input %d nums:", n);
    for (i = 0; i < n; i++)
        /**********found**********/
        scanf("%d", (p + i));
    for (i = 0; i < n; i++)
        aver = aver + p[i];
    aver = aver / n;
    k = 0;
    for (i = 0, j = 0; i < n; i++)
        if (p[i] >= aver)
        /**********found**********/
        {
            p[j++] = p[i];
            k++;
        }
    for (i = 0; i < k; i++)
        printf("%d  ", p[i]);
    printf("\n");
}
