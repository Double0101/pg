#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main()
{
	int a[10][10] = {INT_MAX};
	int *ap = (int*)a;
	for (int i = 0; i < 99; ++i)
	{
		printf("%d\n", ap[i]);
	}
	return 0;
}