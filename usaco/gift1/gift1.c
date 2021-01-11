/*
ID: shchenc1
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>

char name[10][16];
int money[10];
int n = 0;

char tn[16];

int ibyn(char tn[]) {
    for (int i=0; i<n; ++i) {
        if (strcmp(tn, name[i]) == 0)
            return i;
    }
    return -1;
}

void
main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    fscanf(fin, "%d", &n);
    for (int i=0; i<n; ++i) {
        fscanf(fin, "%s", name[i]);
    }
    for(;;) {
        int total, tc, ec;
        fscanf(fin, "%s", tn);
        fscanf(fin, "%d %d", &total, &tc);
        if (tc == 0)
            break;
        ec = total/tc;
        money[ibyn(tn)] -= ec*tc;
        for (int i=0; i<tc; ++i) {
            fscanf(fin, "%s", tn);
            money[ibyn(tn)] += ec
        }
    }
    for (int i=0; i<n; ++i) {
        printf("%s %d\n", name[i], money[i]);
    }
    exit (0);
}
