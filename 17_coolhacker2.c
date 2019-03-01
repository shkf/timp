#include <stdio.h>
#include <math.h>

int main(void)
{
int n;
int a;
int sum = 0;
int i;
int k;
scanf ("%d",&n);
for(i = 0; i < n; i++)
{
scanf ("%d", &a);
k = (pow((-1),(i + 1)) * pow(a, 2));
sum = sum + k; 
}
printf ("%d\n", sum);
return 0;
}
