/* 1002 A + B Problem II */
#include <stdio.h>
#include <string.h>

char a[1001];
char b[1001];
char buf[1002];

char* sum(char*, int, char*, int);

int main()
{
    int n;
    char* r;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {

        scanf("%s", a);
        scanf("%s", b);
        int as = (int)strlen(a);
        int bs = (int)strlen(b);
        r = sum(a, as, b, bs);
        if (i > 1)
            putchar('\n');
        printf("Case %d:\n%s + %s = %s\n", i, a, b, r);
    }
    return 0;
}

char* sum(char* a, int as, char* b, int bs) {
    if (as > bs)
        return sum(b, bs, a, as);
    int rs = bs + 1;
    char rc;
    buf[rs] = '\0';
    char c = 0;
    while (--bs >= 0) {
        --as;
        --rs;
        rc = b[bs] + c;
        if (as >= 0) {
            rc += a[as] - '0';
        }
        else if (c == '\0') {
            buf[rs] = rc;
            break;
        }
        if (rc > (char)'9') {
            c = '\1';
            rc -= (char)10;
        }
        else {
            c = 0;
        }
        buf[rs] = rc;
    }

    if (c)
    {
        --rs;
        buf[rs] = '1';
        return &buf[0];
    }
    else
    {
        while (--bs >= 0) {
            --rs;
            buf[rs] = b[bs];
        }
        return &buf[1];
    }
}
