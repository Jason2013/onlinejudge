/* 1001 Sum Problem */
#include <stdio.h>

int main()
{
    int n, r;
    while (scanf("%d", &n) != EOF) {

        // METHOD 1: Brute force, correct but not efficient
        //r = 0;
        //for (int i = 1; i <= n; ++i) {
        //    r += i;
        //}

        // METHOD 2: Overflow, wrong
        //r = n * (n + 1) / 2;


        if (n & 1) {
            r = (n + 1) / 2 * n;
        }
        else {
            r = n / 2 * (n + 1);
        }
        printf("%d\n\n", r);
    }
    return 0;
}
