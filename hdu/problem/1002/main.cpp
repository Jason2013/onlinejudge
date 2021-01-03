/* 1002 A + B Problem II */
#include <stdio.h>
#include <string.h>

char a[1001];
char b[1002];
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
        int as = strlen(a);
        int bs = strlen(b);
        if (as < bs) {
            r = sum(a, as, b, bs);
        }
        else {
            r = sum(b, bs, a, as);
        }

        printf("Case %d:\n %s + %s = %s\n\n", i, a, b, r);
    }
    return 0;
}

char* sum(char* a, int as, char* b, int bs) {
    int rs = bs + 1;
    char rc;
    buf[rs] = '\0';
    char c = 0;
    while (--as >= 0) {
        --bs;
        --rs;
        rc = (b[bs] - '0') + (a[as] - '0') + c;
        if (rc > 9) {
            c = 1;
            rc -= 10;
        }
        else {
            c = 0;
        }
        buf[rs] = rc + '0';
    }
    while (--bs >= 0) {
        --rs;
        rc = (b[bs] - '0') + c;
        if (rc > 9) {
            c = 1;
            rc -= 10;
        }
        else {
            c = 0;
        }
        buf[rs] = rc + '0';
    }
    if (c)
    {
        --rs;
        buf[rs] = '1';
        return &buf[0];
    }
    else
    {
        return &buf[1];
    }
}