/* 1.1.7 A+B for Input-Output Practice (VII) */
#include <stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        printf("%d\n\n", a+b);
    }
    return 0;
}
