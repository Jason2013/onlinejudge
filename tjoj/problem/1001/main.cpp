/* 1001 Color Problem */
#include <stdio.h>

int p[11];
int e[21][21];

int pc=0, ec=0, rc=0;

int ptclr(int pt, int clr) {
    for (int i=1; i<=e[pt][0]; ++i)
        if (p[e[pt][i]] == clr)
            return 0;
    return 1;
}

void find(int pt) {
    if (pt > pc) {
        ++rc;
        return;
    }
    for (int clr=1; clr<=4; ++clr) {
        if (ptclr(pt, clr)) {
            p[pt] = clr;
            find(pt+1);
            p[pt] = 0;
        }
    }
}

void adde(int a, int b) {
    e[a][++e[a][0]]=b;
    e[b][++e[b][0]]=a;
}

int main()
{
    int a, b;
    int ac, bc;
    scanf("%d %d", &pc, &ec);
    for (int i=0; i<ec; ++i) {
        scanf("%d %d", &a, &b);
        adde(a, b);
    }
    find(1);
    printf("%d\n", rc);
    return 0;
}
