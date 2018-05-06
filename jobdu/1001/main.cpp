#include <cstdio>
using namespace std;

const int msize = 10;
int a[msize][msize];
int b[msize][msize];

void get_mx(unsigned int m, unsigned int n, int mx[][msize])
{
    for (unsigned int i = 0; i < m; ++i)
    {
        for (unsigned int j = 0; j < n; ++j)
            scanf("%d", &mx[i][j]);
    }
}

void add_mx(unsigned int m, unsigned int n, int a[][msize], int b[][msize])
{
    for (unsigned int i = 0; i < m; ++i)
    {
        for (unsigned int j = 0; j < n; ++j)
            a[i][j] += b[i][j];
    }
}

size_t zero_row(unsigned int m, unsigned int n, int mx[][msize])
{
    size_t r = 0;
    for (size_t i = 0; i < m; ++i)
    {
        size_t j;
        for (j = 0; j < n; ++j)
        {
            if (mx[i][j] != 0)
                break;
        }
        if (j == n) ++r;
    }
    return r;
}

size_t zero_col(unsigned int m, unsigned int n, int mx[][msize])
{
    size_t r = 0;
    for (size_t i = 0; i < n; ++i)
    {
        size_t j;
        for (j = 0; j < m; ++j)
        {
            if (mx[j][i] != 0)
                break;
        }
        if (j == m) ++r;
    }
    return r;
}

int main()
{
    unsigned int m, n;
    while (scanf("%d", &m) != EOF)
    {
        if (m == 0)
            break;

        scanf("%d", &n);

        get_mx(m, n, a);
        get_mx(m, n, b);

        add_mx(m, n, a, b);

        printf("%d\n", zero_col(m, n, a) + zero_row(m, n, a));
    }
    return 0;
}
