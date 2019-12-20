/* Selection sort - Sort N student names in alphabetic order */

#include <stdio.h>
#include <string.h>
#define MAX 20

int main(){
	char names[MAX][MAX], sorted[MAX][MAX], temp[MAX];
	int n, i, j;

	printf("\nEnter number of students \n");
	scanf("%d", &n);
	
	printf("Enter names (Press RETURN after each name):\n");
	for(i = 0; i < n; i++)
		scanf("%*c%[^\n]s", names+i);

	printf("\nNames after sorting:\n");
	for(i = 0; i < n; i++)
		for(j = i+1; j < n; j++)
			if(strcmp(names+i, names+j) > 0){
				strcpy(temp, names+i);
				strcpy(names+i, names+j);
				strcpy(names+j, temp);
			}

	for(i = 0; i < n; i++)
		printf("%s\n", names+i);

}
