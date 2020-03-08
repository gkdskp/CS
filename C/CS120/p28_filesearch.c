/* A text file ‘STUDENT.DAT’ contains regno, name and 6 marks in the following format
   ------  ------  ------  ------  ------  ------  ------  ------
 | Regno | Name  | Mark1 | Mark2 | Mark3 | Mark4 | Mark5 | Mark6 |
   ------  ------  ------  ------  ------  ------  ------  ------
 | 6     | 25    | 3     | 3     | 3     | 3     | 3     |3      | 
   ------  ------  ------  ------  ------  ------  ------  ------
Input a register number and display the mark list corresponding to that student.

INPUT FORMAT:
1 name1 10 10 01 10 10 10 
2 name2 12 12 21 21 12 21
3 name3 13 13 31 31 13 31
*/

#include <stdio.h>

void main(){
	int reg, m[6], i, j, num, item;
	char n[50];

	FILE *fp;
	fp=fopen("student.dat", "r");
	if(!fp){
		printf("student.dat does not exists");
		printf("\nMake sure student.dat exists\n");
		return;
	}
	
	printf("Enter a registration number to search: ");
	scanf("%d", &item);
	
	i = 0;
	printf("\n");
	
	while((fscanf(fp, "%2d %s %2d %2d %2d %2d %2d %2d",
	&reg, n, &m[0], &m[1], &m[2], &m[3], &m[4], &m[5])) != EOF){
		if(reg == item)
			for(i = 0; i < 6; i++){
				printf("Mark %d: %d\n", i+1, m[i]);
			}
		i++;
	}
	printf("\n");
	
	fclose(fp);
}

