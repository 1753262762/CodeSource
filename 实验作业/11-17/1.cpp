#include <stdio.h> /* sy7-1.c */
#include <math.h>
main()
{
    int i, k;
    float a[10], aver = 0, b, d, *p = a;
    for (i = 0; i < 10; i++)
        scanf("%f", p + i);
    for (i = 0; i < 10; i++)
        aver += p[i];
    aver /= 10;
    k = 0;
    d = fabs(p[0] - aver);
    for (i = 1; i < 10; i++)
    {
        b = fabs(p[i] - aver);
        if (b < d)
        {
            d = b;
            k = i;
        }
    }
    printf("Average value: %f\n", aver);
    printf("near value: %f,  %f\n", d, p[k]);
    system("pause");
}
