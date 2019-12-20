/*  Find the value of sin(x) and cos(x) */

#include <stdio.h>
#include <math.h>

int fact(int n){
	if(n ==0 || n==1)
		return 1;
	else
		return n * fact(n-1);
}

void main(){
	double rad, sinx = 0.0, cosx = 0.0;
	int angle, i, j, l = 1, k = 1, factc = 1, facts = 1;

	printf("\nEnter angle (0 - 180): ");
	scanf("%d", &angle);
	rad = (double) angle * (3.14/180);

	for(j=0; j <= 12; j += 2){
		cosx += (l*(float)(pow(rad, j))/fact(j));
		sinx += l*(float)(pow(rad, j+1))/fact(j+1);
		l *= -1;
	}
	
	printf("cos(%d) = %lf\t sin(%d) = %lf\n", angle, cosx, angle, sinx);

}
