#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
int main(void)
{
int n;
scanf ("%d", &n);
int sum = 0;
int i;
int k;
for(i = 0; i < n; i++)
{
scanf("%d", &k);
sum = sum + k;
}
printf("%d\n", sum);
return 0;
}
