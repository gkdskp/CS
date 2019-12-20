/* Store the regno, name and 4 marks of a set of students in an array of structure
and display the details along with total marks in the descending order of total marks */

#include <stdio.h>

struct Student{
	int rno;
	char name[30];
	int marks[4];
	int totmarks;	
}s[20], temp;

int main(){
	int n, i, j;
	printf("\nEnter number of students: ");
	scanf("%d", &n);

	printf("\nEnter details of students. Format:\n");
	printf("rollno first_name mark1 mark2 mark3 mark4\n");
	for(i = 0; i < n; i++){
		s[i].totmarks = 0;
		scanf("%*c%d %s ", &(s[i].rno), (s[i].name));
		for(j = 0; j < 4; j++){
			scanf("%d", &(s[i].marks[j]));
			s[i].totmarks += s[i].marks[j];
		}
	}

	/* Bubble sort */
	for(i = 0; i < n; i++)
		for(j = 0; j < n-i-1; j++){
			if(s[j].totmarks < s[j+1].totmarks){
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}

	printf("Sorted List:\n");
	printf("Reg. No\tName\tTotal Marks");
	printf("\n--------------------------------------\n");

	for(i = 0; i < n; i++){
		printf("%d\t%s\t%d\n", s[i].rno, s[i].name, s[i].totmarks); 	
	}
}
