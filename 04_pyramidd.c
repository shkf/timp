#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int sort2(int *num, int root, int lenght)
{
    int tmp =0;
	int max;
	int ac = 0;
	while ((root * 2 <= lenght) && (!ac))
	{
		if (root * 2 == lenght) {
		    tmp++;
			max = root * 2;
		}
		else if (num[root * 2] > num[root * 2 + 1]) {
			
			tmp++;
			max = root * 2;
		}
		else {
		    tmp++;
			max = root * 2 + 1;
		}
		if (num[root] < num[max])
		{
		    tmp++;
			int temp = num[root];
			num[root] = num[max];
			num[max] = temp;
			root = max;
		}
		else
		{tmp++;
			ac = 1;
		}
		
	}
	return tmp;
}
int sort(int *num, int array_size)
{ int tmp = 0;
	for (int i = (array_size / 2) ; i >= 0; i--)
		tmp+=sort2(num, i, array_size);
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = num[0];
		num[0] = num[i];
		num[i] = temp;
		tmp+=sort2(num, 0, i - 1);
	}
	return tmp;
}
int main()
{
    srand(time(0));
  clock_t start,stop;
unsigned long t;
    double rez,sr_rez = 0;
int n[15] = {1,2,3,4,5,10,15,20,25,30,50,75,100,250,500};
for (int f = 0 ; f <15;f++)
{
int *a;
a = (int*)malloc(n[f] * sizeof(int));
start = clock();
for (int j = 0;j <1000;j++)
{
for (int i = 0;i < n[f]; i ++)
{
a[i] = rand()%  10000 - 8419;
} 
rez = sort(a,n[f]);
sr_rez +=rez;
}
stop = clock();
printf("%d\n %f \n",n[f],sr_rez/1000);
sr_rez = 0;
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*1000000);
start ,stop = 0;
clock_rez = 0;
}
}
