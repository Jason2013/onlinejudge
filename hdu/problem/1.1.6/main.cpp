/* 1.1.6 A+B for Input-Output Practice (VI) */
#include <stdio.h>

int main()
{
    int n, m, sum;
    while (scanf("%d", &n) == 1) {
        sum = 0;
        for (int i=0; i<n; ++i) {
            scanf("%d", &m);
            sum += m;
        }
        printf("%d\n", sum);
    }
    return 0;
}
