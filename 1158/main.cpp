#include <stdio.h>

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        int p=200;
        int y;
        for (y=1; y<=20; ++y)
        {
            if (n*y >= p)
            {
                printf("%d\n", y);
                break;
            }
            p = p * (100 + k) / 100;
        }
        if (y>20)
        {
            printf("Impossible\n");
        }
    }

    return 0;
}
