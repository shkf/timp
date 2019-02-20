#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main (void)
{
	int a, b;
	float ch;
	scanf("%d", &a);
	scanf("%d", &b);
	ch = pow((double) a, (double) b);
	printf("%f", ch);
	return 0;
}
