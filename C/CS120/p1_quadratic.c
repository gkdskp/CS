/* Roots of quadratic equation ax2+bx+c=0 */

#include <stdio.h>
#include <math.h>

void main()
{
	int a, b, c, d;
	float root1, root2, real, complex;

	printf("Enter a, b and c: \n");
	scanf("%d%d%d", &a, &b, &c);
	d = b*b - 4*a*c;

	if (d > 0)
	{
		root1 = (float)(-b + sqrt(d))/(2*a);
		root2 = (float)(-b - sqrt(d))/(2*a);
		printf("Roots are %f and %f\n", root1, root2);
	}

	else if (d == 0)
	{
		root1 = root2 = ((float)(-b + sqrt(d)))/(2*a);
		printf("Root of the equation is %f\n", root1);
	}

	else if(d < 0)
	{
		real = (float)(-b)/(2*a);
		complex = (float)(sqrt(-d)/(2*a));
		printf("Roots are %f + i%f and %f - i%f\n", real, complex, real, complex);
	}
}
