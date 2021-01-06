#include <stdio.h>

int main()
{
	/* code */
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);

	a = a + b;
	if (a < 0) {
		printf("-");
		a = 0-a;
	}

	if (a == 0)
	{
		printf("0\n");
		return 0;
	}

	int s = 10000000;
	while (s > a) s /= 10;
	while (s != 0) {
		int c = a/s;
		printf("%d", c);
		if (s == 1000 || s == 1000000) printf(",");
		a = a%s;
		s /= 10;
	}
	printf("\n");
	return 0;
}