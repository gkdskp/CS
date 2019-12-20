/* Find the average of a set of numbers using command line argument */

#include <stdio.h>

int atoi(char *);

int main(int argc, char *argv[]){
	int sum = 0, i;
	float avg;

	if(argc == 1){
		printf("\nPlease pass the numbers as command line arguments\n");
		return 1;
	}

	for(i = 1; i < argc; i++)
		sum += atoi(*(argv+i));	
	
	avg = ((float)sum)/(argc-1);

	printf("\nThe average is %.2lf\n", avg);
}

