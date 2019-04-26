#include <stdio.h>
#include <stdlib.h>

void sort1(int* arr, int left, int right)
{
	int i = left, j = right;
	double tmp, b = arr[(left + right) / 2];
	do {
		while (arr[i] < b)
			i++;
		while (arr[j] > b)
			j--;
		if (i <= j)
		{
			if (i < j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < right)
		sort1(arr, i, right);
	if (left < j)
		sort1(arr, left, j);
}
int main()
{
	int a, i;
	scanf("%d", &a);
	int arr[a];
	for (i = 0; i<a; i++) {
		scanf("%d", &arr[i]);
	}
	sort1(arr, 0, a - 1);
	for (i = 0; i<a; i++) {
		printf("%d ", arr[i]);
	}
	printf("\a");
}
