/*  Binary to Decimal conversion */

#include <stdio.h>
#include <math.h>

void main()
{
	int bin, dec = 0, i = 0;
	printf("Enter binary number\n");
	scanf("%d", &bin);
	while(bin != 0)
	{
		dec = dec + ((bin % 10) * pow(2, i));
		bin = bin/10;
		i++;
	}
	printf("Corresponding decimal is:%d\n", dec);
}
