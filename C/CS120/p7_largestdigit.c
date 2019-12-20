/* Find the largest digit in a number */

#include <stdio.h>

void main(){
	int n, ld = 0, d;
	printf("Enter number\n");
	scanf("%d", &n);
	while(n != 0){
		d = n % 10;
		if(d > ld) ld = d;
		n = n / 10;
	}
	printf("The largest digit is %d\n", ld);
}
