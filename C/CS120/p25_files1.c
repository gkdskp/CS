/* Display the frequency of each alphabet and each digits in a given text file */

#include <stdio.h>

void digitFreq(char *s)
{
	static int d[10];
	int i;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] >= '0'&& s[i] <= '9')
			d[s[i] - '0']++;
	}
	printf("\nFrequency of digits:\n"); 
	for(i = 0; i < 10; i++){
		if(d[i] != 0)
                        printf("%d: %d\n", i, d[i]);
	}
}

void charFreq(char *s){
        static int a[26], b[26], i;
	char c;
        for(i = 0; s[i] != '\0'; i++){

                if(s[i] >= 'a' && s[i] <= 'z')
                	a[s[i] - 'a']++;
		
		if(s[i] >= 'A' && s[i] <= 'Z')
                        b[s[i] - 'A']++;
	}
	printf("\nFrequency of alphabets:\n");
	for(i = 0; i < 26; i++){
		if(a[i] != 0){
			c = i + 'a';
			printf("%c: %d\n", c, a[i]);
		}
		if(b[i] != 0){
                        c = i + 'A';
                        printf("%c: %d\n", c, b[i]);
                }
	}
}

void main(){
	printf("\nMake sure the text file is saved as file.txt\n");
	FILE *fp;
	int i;
	char s[200], ch;
	fp=fopen("file.txt", "r");
	for(i = 0; (ch = getc(fp)) != EOF; i++)
		s[i] = ch;
	s[i] = '\0';
	digitFreq(s);
	charFreq(s);
	fclose(fp);
}

