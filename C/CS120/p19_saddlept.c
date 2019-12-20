/* Write a program to:
	(i) Find the saddle point of a matrix. (Find the minimum from each row and maximum 
	    from each column, if they are the same, the position of the element is 
	    the saddle point)
	(ii) Print the upper diagonal and lower diagonal elements
	(iii) Interchange any two rows and columns
*/

#include <stdio.h>
#define MAX 50

int min(int[][MAX], int, int, int);
int max(int[][MAX], int, int, int);

int min(int a[][MAX], int r, int n, int num){
	int j = 0, s;
	s = a[r][0];

	for(j = 0; j < n; j++)
		if(a[r][j] < s)
			s = a[r][j];

	if(s == num)
		return 1;

	return 0;
}

int max(int a[][MAX], int c, int m, int num){
	int i = 0, l;
        l = a[0][c];

        for(i = 0; i < m; i++)
                if(a[i][c] > l)
                        l = a[i][c];
        
	if(l == num)
                return 1;
        
	return 0;
}

void main(){
        int a[MAX][MAX], m, n, i, j, x[10], y[10], c[10], p, c1, c2, r1, r2, temp;
        printf("\nEnter number of rows and columns in mxn format:\n");
        scanf("%dx%d", &m, &n);

        printf("\nEnter the elements:\n");
        for(i = 0; i < m; i++){
                for(j = 0; j < n; j++)
                        scanf("%d", &a[i][j]);
        }

	p = 0;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(min(a, i, n, a[i][j]) && max(a, j, n, a[i][j])){
				x[p] = i;
				y[p] = j;
				p++;
			}
		}
	}

	printf("\nSaddle points are: \n");
	for(i = 0; i < p; i++)
		printf("%d at (%d , %d)\n", a[x[i]][y[i]], x[i],y[i]);

	printf("\nUpper diagonal elements: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			if(i > j)
				printf("%d ", a[i][j]);
		printf("\n");
	}

	printf("\nLower diagonal elements: \n");
        for(i = 0; i < m; i++){
                for(j = 0; j < n; j++)
                        if(i < j)
                                printf("%d ",a[i][j]);
			else
				printf("  ");
                printf("\n");
        }

	printf("\nRows to be interchanged:\n");
	printf("Type row number: ");
	scanf("%d",&r1);
	r1--;
	printf(" <-> ");
        scanf("%d",&r2);
	r2--;

	for(j = 0; j < n; j++){
		temp = a[r1][j];
		a[r1][j] = a[r2][j];
		a[r2][j] = temp;
	}

	printf("Resultant matrix:\n");
	for(i = 0; i < m; i++){
                for(j = 0; j < n; j++)
                        printf("%d ", a[i][j]);
                printf("\n");
        }

	printf("\nColumns to be interchanged:\n");
        printf("Type column number: ");
        scanf("%d", &c1);
	c1--;
	printf(" <-> ");
        scanf("%d", &c2);
	c2--;
        for(i = 0; i < m; i++){
                temp = a[i][c1];
                a[i][c1] = a[i][c2];
                a[i][c2] = temp;
        }
	printf("Resultant matrix:\n");
	for(i = 0; i < m; i++){
                for(j = 0; j < n; j++)
                        printf("%d ", a[i][j]);
                printf("\n");
        }


}

