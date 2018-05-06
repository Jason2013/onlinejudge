#include <stdio.h>

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        float p=200.0f;
        float ratio = 1.0f + (float)k/100.0f;
        int y;
        for (y=1; y<=20; ++y)
        {
            p *= ratio;
            if ((float)(n*y) >= p)
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
