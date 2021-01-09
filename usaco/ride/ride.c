/*
ID: shchenc1
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>

char comet[8];
char group[8];

int val(char s[]) {
    int r=1;
    int i=0;
    while(s[i] != '\n' && s[i] != '\0') {
        printf("%c ", s[i]);
        r = r * (s[i] - 'A' + 1) % 47;
        ++i;
    }
    return r;
}

void
main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    fgets(comet, sizeof(comet), fin);
    fgets(group, sizeof(group), fin);
    fprintf(fout, "%s\n", val(comet) == val(group) ? "GO" : "STAY");
    exit (0);
}
