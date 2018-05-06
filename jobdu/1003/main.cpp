#include <cstdio>
#include <cstdlib>
using namespace std;

void fmt(char * s)
{
    char * p = s;
    while (*s != '\0')
    {
        if (*s != ',')
        {
            *p = *s;
            ++p;
        }
        ++s;
    }
    *p = '\0';
}

char na[20], nb[20];

int main()
{
    while (scanf("%s %s", na, nb) != EOF)
    {
        fmt(na);
        fmt(nb);
        printf("%d\n", atoi(na)+atoi(nb));
    }
    return 0;
}

