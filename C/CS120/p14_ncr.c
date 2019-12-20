/* Write a recursive function for finding factorial. Using this find nCr */

#include <stdio.h>

int fact(int);

void main(){
	int ncr, n, r,  rfact, nrfact, nfact;

	printf("\nEnter n and r\n");
	scanf("%d%d", &n, &r);

	if(n >= r){
		nfact = fact(n);
		rfact = fact(r);
		nrfact = fact(n-r);
		ncr = nfact/(rfact * nrfact);
		printf("\nC(%d, %d) is %d\n", n, r, ncr);
	}else
		printf("\nInvalid option\n");
}

int fact(int n){
	if(n == 1 || n == 0)
		return 1;
	else
		return n * fact(n-1);
}
