#include <cstdio>
using namespace std;

int n;
int x[1000];
int y[1000];
int z[1000];
int z_idx;

void get_n(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &arr[i]);
    }
}

void output_n(int * arr, int n)
{
    for (int i=0; i<n; ++i)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int post_order(int pre_s, int pre_e, int mid_s, int mid_e)
{
    if (pre_s == pre_e && mid_s == mid_e)
    {
        return 0;
    }
    int root = x[pre_s], i;

    for (i=mid_s; i< mid_e; ++i)
    {
        if (root == y[i])
            break;
    }
    if (i == mid_e)
        return -1;

    int succ = post_order(pre_s +1, pre_s+1+i-mid_s, mid_s, i);
    if (succ)
        return succ;

    succ = post_order(pre_s+1+i-mid_s, pre_e, i+1, mid_e);
    if (succ)
        return succ;

    z[z_idx++] = root;
    return 0;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        get_n(x, n);
        get_n(y, n);

        int succ = 0;
        z_idx = 0;
        succ = post_order(0, n, 0, n);

        if (succ == 0)
            output_n(z, n);
        else
            printf("No\n");
    }
    return 0;
}
