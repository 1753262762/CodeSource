#include <stdio.h>

main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    for (int i = 1; i <= a; i++)
    {
        int f = i;
        while (f > 0)
        {
            int k = f % 10;
            f = f / 10;
            if (k == b)
            {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}