#include <cstdio>
using namespace std;

const int nsize = 1000000;
int s1[nsize];
int s2[nsize];

int n1, n2;

bool reads(int * n, int s[])
{
    if (scanf("%d", n) == EOF)
        return false;

    for (int i=0; i<*n; ++i)
    {
        scanf("%d", &s[i]);
    }
    return true;
}

int med(int n1, int s1[], int n2, int s2[])
{
    int med = (n1+n2-1)/2;
    int i1,i2,ix;
    int r;
    i1=i2=ix=0;
    while (i1<n1 &&i2<n2)
    {
        if (s1[i1]<s2[i2])
        {
            if (ix==med)
            {
                r= s1[i1];
                break;
            }
            ++i1;
        }
        else
        {
            if (ix==med)
            {
                r= s2[i2];
                break;
            }
            ++i2;
        }
        ++ix;
    }

    if (i1<n1 && i2<n2)
        return r;

    if (i1 == n1)
        return s2[med-ix+i2];
    return s1[med-ix+i1];
}

int main()
{
    while (reads(&n1, s1) && reads(&n2, s2))
    {
        printf("%d\n", med(n1, s1, n2, s2));
    }
    return 0;
}
