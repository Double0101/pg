#include <stdio.h>

float fa[1001] = {0};

int main()
{
	int a, b, co;
	float f;
	for (int i = 0; i < 2; ++i)
	{
		scanf("%d", &a);
		while (a--) {
			scanf("%d%f", &b, &f);
			fa[b] += f;
		}
	}

	for (int i = 0; i < 1001; ++i)
		if (fa[i]) ++co;

	printf("%d", co);
	for (int i = 1000; i >= 0; --i)
	{
		if (fa[i]) {
			printf(" %d %.1f", i, fa[i]);
		}
	}
	printf("\n");

	return 0;
}