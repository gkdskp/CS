/* Input a line of text and display the palindrome words in it. Write a function each for:
	(i) Checking whether a string is palindrome or not.
	(ii) To count the no.of vowels and digits in the string.
	(iii) Search for a substring & replace with a new substring. */

#include <stdio.h>
#include <string.h>

void lower(char []);
void vowels(char []);
void subfind(char [], char [], char []);
int pal(char []);

void lower(char s[]){
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
}

int pal(char s[]){
	char r[50], t[50];
	int i, p, l;
	strcpy(t, s);
	lower(t);
	l = strlen(s);
	p = l-1;
	for(i = 0; i < l; i++){
		r[i] = t[p];
		p--;
	}
	r[i] = '\0';
	if(strcmp(r,t) == 0)
		return 1;
	return 0;
}

void vowels(char s[]){
	int i = 0, v = 0, d = 0;
	while(s[i] != '\0'){
		switch(s[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':v++;
				break;
		}

		if(s[i] >= '0' && s[i] <= '9')
			d++;
		i++;
	}

	printf("\nNumber of vowels: %d\n", v);
	printf("Number of digits: %d\n", d);
}

void subfind(char s[], char o[], char n[]){
	int sl, ol, nl, i, j, k, f, start, p[50];
	sl = strlen(s);
	ol = strlen(o);
	nl = strlen(n);
	i = 0;
	k = 0;
	while(i < sl){
		f = 0;
		j = 0;
		start = i;
		while(s[i] == o[j]){
			j++;
			i++;
		}
		if(j == ol){
			p[k] = start;
			k++;
		}
		i++;
	}
	i = 0;
	k = 0;
	while(i < sl){
		if(i != p[k]){
			printf("%c", s[i]);
			i++;
		}
		else{
			for(j = 0; j < nl; j++)
				printf("%c", n[j]);
			k++;
			i += ol;
		}
	}
	printf("\n");
}

void main(){
	char w[100][50], s[100], n[100], sub[100], n1[100];
	int i = 0, j = 0, k = 0;

	printf("Enter a line of text: ");
	scanf("%[^\n]", s);
	strcat(s, " ");
	
	while(s[i] != '\0'){
		if(s[i] != ' '){
			n[k] = s[i];
			k++;
		}
		else{
			n[k] = '\0';
			k = 0;
			strcpy(w[j], n);
			j++;
		}
		i++;
	}

	printf("\nPalindrome words are: ");
	for(i = 0; i < j; i++)
		if(pal(w[i]) == 1)
			printf("%s\n", w[i]);
	
	vowels(s);
	printf("\nEnter the substring: ");
	scanf("%*c%[^\n]", sub);
	printf("Enter the new string: ");
	scanf("%*c%[^\n]", n1);
	subfind(s, sub, n1);
}

