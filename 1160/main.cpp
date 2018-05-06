#include <stdio.h>

void f(int plate, int apple, int* plates, int n, int * c)
{
	//printf("f(%d, %d)\n", plate, apple);
	if (plate == n)
	{
		return;
	}
	for (int a = 0; a <= apple; a++)
	{
		int p;
		for (p = 0; p < plate; p++)
		{
			if (a > plates[p])
			{
				break;
			}
		}
		if (p < plate)
		{
			return;
		}
		plates[plate] = a;
		if (plate == n-1 && apple == a)
		{
			(*c)++;
			/* for (int i = 0; i < n; i++) */
			/* { */
			/* 	printf("%d ", plates[i]); */
			/* } */
			/* printf("\n"); */
			return;
		}
		f(plate + 1, apple - a, plates, n, c);
	}
}

int main()
{
    int m, n;
	int plates[10];
	int c;
	int count;
	scanf("%d", &count);

    while (count--)
    {
		scanf("%d %d", &m, &n);
		c = 0;
		f(0, m, plates, n, &c);
		printf("%d\n", c);
    }

    return 0;
}
