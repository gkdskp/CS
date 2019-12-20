/* Find GCD and LCM of two numbers */

#include <stdio.h>

void main()
{
	int a, b, c, d, r, lcm;
	printf("\nEnter two numbers:\n");
	scanf("%d%d", &a, &b);
	c = a;
	d = b;

	/* HCF */
	do
	{
		r = a % b;
		a = b;
		b = r;
	}
	while( b != 0 );

	/* LCM */
	lcm = (c * d)/a;

	printf("\nGCD is %d\n", a);
	printf("LCM is %d\n", lcm);
}
