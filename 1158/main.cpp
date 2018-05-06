#include <stdio.h>

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        int y;
        for (y=4; y<=20; ++y)
        {
            if (n*y*100 >= (200 * (100 + k)))
            {
                printf("%d\n", y);
                break;
            }
        }
        if (y>20)
        {
            printf("Impossible\n");
        }
    }

    return 0;
}
