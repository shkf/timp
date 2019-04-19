#include <stdio.h>
#include <stdlib.h>

void rascheska(int *array, int lenght)
{
	if (array && lenght)
	{
		int jump = lenght;
		int i;
		int sm = 1;
		while (jump > 1 || sm)
		{
			if (jump > 1)
				jump /= 1.24733;
			sm = 0;
			for (i = 0; i + jump < lenght; ++i)
				if (array[i + jump] < array[i])
				{
					int tmp;
					tmp = array[i];
					array[i] = array[i + jump];
					array[i + jump] = tmp;
					sm = 1;
				}
		}
	}
}
int main()
{
	int a, i;
	scanf("%d", &a);
	int arr[a];
	for (i = 0; i<a; i++) {
		scanf("%d", &arr[i]);
	}
	rascheska(arr, a);
	for (i = 0; i<a; i++) {
		printf("%d ", arr[i]);
	}
	printf("\a");
	return 0;
}
