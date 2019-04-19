#include <stdio.h>
#include <stdlib.h>

void shell(int *array, int size)
{
	int i, j;
	int sm;
	int tmp;
	for (sm = size / 2; sm > 0; sm /= 2)
		for (i = sm; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= sm; j -= sm)
			{
				if (tmp < array[j - sm])
					array[j] = array[j - sm];
				else
					break;
			}
			array[j] = tmp;
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
	shell(arr, a);
	for (i = 0; i<a; i++) {
		printf("%d ", arr[i]);
	}
	printf("\a");
	return 0;
}
