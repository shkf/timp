#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main (void)
{
	int a, b, ch;
	scanf("%d", &a);
	scanf("%d", &b);
	ch = pow((double) a, (double) b);
	printf("%d\n", ch);
	return 0;
}
