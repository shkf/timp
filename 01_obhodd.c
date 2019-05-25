#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int sift(int *numbers, int head, int down)
{
    int temp = 0;
    int max, success = 0;
    while ((head * 2 <= down) && (!success))
    {
        if (head * 2 == down) {
          temp++;
          max = head * 2;
        }
        else if (numbers[head * 2] > numbers[head * 2 + 1]) {
         temp++; 
         max = head * 2;
        }
        else {temp++;
          max = head * 2 + 1;
        }
         temp++;
        if (numbers[head] < numbers[max])
        {
            int temp1 = numbers[head];
            numbers[head] = numbers[max];
            numbers[max] = temp1;
            head = max;
            temp++;
        }
        else {
          success = 1;
             }

    }
  return temp;
}

int funcPyramidSort(int *numbers, int arr_len)
{
    int temp = 0;
    for (int i = (arr_len / 2) ; i >= 0; i--) {
      temp+=sift(numbers, i, arr_len - 1);
    }

    for (int i = arr_len - 1; i >= 1; i--)
    {
        int temp1 = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp1;
        temp+=sift(numbers, 0, i - 1);
    }
    return temp;
}

int main()
{
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
rez = funcPyramidSort(a,n[f]);
sr_rez +=rez;
}
stop = clock();
printf("%d\n %f \n",n[f],sr_rez/1000);
sr_rez = 0;
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*100000);
start ,stop = 0;
clock_rez = 0;
}
}
