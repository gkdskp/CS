/* Second largest of a set of N numbers */

#include <stdio.h>

void main()
{
	int N, n1, n2, n, l, sl, i;
	printf("Enter N (greater than 2)\n");
	scanf("%d", &N);
	printf("Enter numbers\n");
	scanf("%d%d", &n1, &n2);

	l = (n1 > n2) ? n1: n2;
	sl = (n1 > n2) ? n2: n1;

	for(i = 0; i < N-2; i++)
	{
		scanf("%d", &n);
		if(n > l)
		{
			sl = l;
			l = n;
		}
		else if(n == l)
		{
			continue;
		}
		else if(n > sl)
		{
			sl = n;
		}
		if(l == sl)
		{
			sl = n;
		}
	}

	if(l != sl) printf("Second largest number is %d\n", sl);
	else printf("Largest number is %d\n", sl);
}
