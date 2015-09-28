#include <cstdio>
using namespace std;

inline bool in(int t, int a, int b)
{
    return (a-b)*(a-b)<=(t*t);
}

inline int max(int a, int b)
{
    return a>b ? a:b;
}

float grade(int p, int t, int g1, int g2, int g3, int gj)
{
    if (in(t,g1,g2))
        return (g1+g2)/2.0f;

    if (in(t,g1,g3))
    {
        if (in(t,g2,g3))
            return max(max(g1,g2),g3);
        return (g1+g3)/2.0f;
    }
    else
    {
        if (in(t,g2,g3))
            return (g2+g3)/2.0f;
        return gj;
    }
}

int main()
{
    int p, t, g1, g2, g3, gj;
    while (scanf("%d %d %d %d %d %d", &p, &t, &g1, &g2, &g3, &gj) != EOF)
    {
        printf("%.1f\n", grade(p, t, g1, g2, g3, gj));
    }
    return 0;
}
