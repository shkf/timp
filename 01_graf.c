#include <stdlib.h>
#include <stdio.h>


void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* Task1(int mas[5][5], int lengt, int Start)
{
	int temp_mas[5] = { 1, 1, 1, 1, 1 };
	int* temp_ar = (int*)malloc(lengt * sizeof(int));
	for (int i = 0; i < lengt; i++) {
		if (i == Start)
			temp_ar[i] = 0;
		else
			temp_ar[i] = 1000;
	}
	int t, MinRoad, yo; 
	do {
		MinRoad = 1000;
		yo = 1000;
		for (int i = 0; i < lengt; i++) {
			if ((temp_mas[i] == 1) && (temp_ar[i] < 1000)) {
				MinRoad = temp_ar[i];
				yo = i;
			}
		}
		if (yo != 1000) {
			for (int i = 0; i < lengt; i++) {
				if (mas[yo][i] > 0) {
					t = MinRoad + mas[yo][i];
					if (t < temp_ar[i])
						temp_ar[i] = t;
				}
			}
			temp_mas[yo] = 0;
		}
	} while (yo < 1000);
	return temp_ar;
}
int Task2(int* temp_mas, int mas[5][5], int n, int len_)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				mas[i][j] = 0;
			else {
				if (mas[i][j] == 0)
					mas[i][j] = 1000;
			}
		}
	}
	int temp = 0;
	int z = 0;
	int sum = 0;
	for (int i = 0; i <= n - 1; i++)
		sum += mas[temp_mas[i % 5]][temp_mas[(i + 1) % 5]];
	if (len_ > sum) {
		len_ = sum;
	}
	while (z < 119) {
		sum = 0;
		int j = n - 2;
		while (j != -1 && temp_mas[j] >= temp_mas[j + 1])
			j--;
		if (j == -1)
			z = 119;
		int y = n - 1;
		while (temp_mas[j] >= temp_mas[y])
			y--;
		{
			swap(&temp_mas[j], &temp_mas[y]);
		}
		int l = j + 1;
	    int r = n - 1;
		while (l < r)
			swap(&temp_mas[l++], &temp_mas[r--]);
		for (int i = 0; i <= n - 1; i++)
			sum += mas[temp_mas[i % 5]][temp_mas[(i + 1) % 5]];
		if (l > sum)
			l = sum;
		z++;
	};
	return len_;
}
int main()
{



	int count = 0;
	printf("Введите количество узлов ");
	scanf("%d", &count);
	int array[count][count];

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			printf("Введите ребро идущее из вершины %d в вершину %d :", i + 1, j+ 1);
			scanf("%d", &array[i][j]);
		}
	}



	int* temp_mass_for_task2 = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++)
		temp_mass_for_task2[i] = i;
	int z = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	int start_point ;
	printf("Начальный узел:\n");
	scanf("%d", &start_point);
	int* f = Task1(array, count, start_point - 1);
	for (int i = 0; i < count; i++) {
		if (f[i] <= 9000) {
			printf(" %d -> %d = %d\n", start_point, z , f[i]);
		}
		z++;
	}
	int u = Task2(temp_mass_for_task2, array, count, 9000);
	if (u <= 9000) {
		printf("Контур равен  %d\n", u);
	}
	return 0;
}
