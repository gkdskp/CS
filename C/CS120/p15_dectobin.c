/* Write a recursive function for finding the binary equivalent of a decimal number */

#include <stdio.h>

int bin(int);

void main(){
	int n;

	printf("\nEnter decimal number\n");
	scanf("%d", &n);

	bin(n);
	printf("\n");
}

int bin(int n){
	if(n == 0){
		return 0;
	}
	else{
		bin(n / 2);
		printf("%d", n % 2);
	}
}
