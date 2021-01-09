/* 1001 Color Problem */
#include <stdio.h>

int p[11];
struct edge
{
    int a, b;
};
struct edge e[50];

int pc=0, ec=0, rc=0;

int ptclr(int pt, int clr) {
    for (int i=0; i<ec; ++i) {
        if (e[i].a == pt && p[e[i].b] == clr ||
            e[i].b == pt && p[e[i].a] == clr)
            return 0;
    }
    return 1;
}
void find(int pt) {
    for (int clr=1; clr<=4; ++clr) {
        if (ptclr(pt, clr)) {
            p[pt] = clr;
            if (pt == pc) {
                /* for (int i=1; i<=pc; ++i) */
                /*     printf("%d ", p[i]); */
                /* printf("\n"); */
                ++rc;
            }
            else {
                find(pt+1);
            }
            p[pt] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &pc, &ec);
    for (int i=0; i<ec; ++i) {
        scanf("%d %d", &e[i].a, &e[i].b);
    }
    find(1);
    printf("%d\n", rc);
    return 0;
}
