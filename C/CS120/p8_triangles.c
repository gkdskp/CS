/* Write a menu driven program to print the following patterns using while and do-while. 
No. of lines should be read from the user.

	(i) Floyd’s triangle
	1
	2 3
	3 4 5
	4 5 6 7

	(ii)
	1
	0 1
	1 0 1
	0 1 0 1

	(iii)
	5 4 3 2 1
	4 3 2 1
	3 2 1
	2 1
	1

	(iv) Pascal's triangle
	           1 
	         1  1 
	       1  2  1 
	     1  3  3  1 
	   1  4  6  4  1 

	(v) 
	*   *   *   *
	  *   *   *
	    *   *
	      *
*/

#include <stdio.h>

void main(){
	int i, j, k, n, c, d, e, ifact = 1, ijmodfact = 1, jfact = 1;
	char opt;

	/* Menu */
	printf("\nMenu"
	"\n------------------"
	"\na. Triangle 1"
	"\nb. Triangle 2"
	"\nc. Triangle 3"
	"\nd. Triangle 4"
	"\ne. Triangle 5"
	"\n Choose an option: ");

	scanf("%c", &opt);
	printf("\nEnter number of lines\n");
	scanf("%d", &n);
	printf("\n");
	switch(opt){

		case 'a': /* Floyd's Triangle */
			i = 1;
			while ( i <= n ){
				j = i;
				while( j <= 2*i - 1 ){
					printf("%d ", j);
					j++;
				}
				printf("\n");
				i++;
			}
			break;

		case 'b':
			i = 0;
			while(i < n){
				j = 0;
				while( j <= i ){
					if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) 
						printf("%d ", 1);
					else printf("%d ", 0);
					j++;
				}
				printf("\n");
				i++;
			}
			break;

		case 'c':
			i = n;
			while (i >= 0){
				j = i;
				while(j >= 1){
					printf("%d ", j);
					j--;
				}
				printf("\n");
				i--;
			}
			break;

		case 'd':
			i = 0;
			while(i <= n-1){
				j = 0;
				for(k = 2*(n-i); k > 0; k--){
					printf(" ");
				}
				while ( j <= i ){
					c = i;
					ifact = 1;
					jfact = 1;
					ijmodfact = 1;
					while( c > 0 ){
						ifact = ifact * c;
						c--;
					}
					d = i - j;
					while(d > 0){
						ijmodfact = ijmodfact * d;
						d--;
					}
					e = j;
					while(e > 0){
						jfact = jfact * e;
						e--;
					}
					printf(" %d ", ifact/(jfact * ijmodfact));
					j++;
				}
				printf("\n");
				i++;
			}
			break;

		case 'e':
			i = n;
			while( i >= 1){
				for(k = 0; k < n-i; k++) printf(" "); 
				j = 1;
				while( j <= i){
					printf(" * ");
					j++;
				}
				printf("\n");
				i--;
			}
			break;
	}
}
