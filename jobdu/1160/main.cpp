#include <stdio.h>

void f(int plate, int apple, int* plates, int n, int * c)
{
	if (plate == n)
	{
		return;
	}

	int min = apple;
	for (int p = 0; p < plate; p++)
	{
		int apple_in_plate = plates[p];
		if (min > apple_in_plate)
		{
			min = apple_in_plate;
		}
	}

	int avg_apple = apple / (n - plate);
	for (int a = min; a>= avg_apple; --a)
	{
		if (apple == a)
		{
			(*c)++;
			continue;
		}
		plates[plate] = a;
		f(plate + 1, apple - a, plates, n, c);
	}
}

int main()
{
	int count;
	scanf("%d", &count);

    while (count--)
    {
        int m, n;
        int plates[10];
        int c;
		scanf("%d %d", &m, &n);
		c = 0;
		f(0, m, plates, n, &c);
		printf("%d\n", c);
    }

    return 0;
}
