/* 1.1.8 A+B for Input-Output Practice (VIII) */
#include <stdio.h>

int main()
{
    int n, m, sum, val;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &m);
        sum = 0;
        for (int j=0; j<m; ++j) {
            scanf("%d", &val);
            sum += val;
        }
        if (i>0)
            putchar('\n');
        printf("%d\n", sum);
    }
    return 0;
}
