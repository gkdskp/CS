/* Write a function to check whether a counting number is prime or not. 
Using this function display the prime numbers in first N counting numbers */

#include <stdio.h>
#include <math.h>

int prime(int);

void main(){
	int n, i = 2;

	printf("\nEnter N: \n");
	scanf("%d", &n);

	while(i < n){
		if(prime(i))
			printf("%d\t", i);
		++i;
	}
	printf("\n");
}

int prime(int n){
	int i;
	for(i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
