/*  Implement the following string library functions using pointers:
	1. string length
	2. string copy
	3. string comparison
	4. string concatenation */

#include <stdio.h>
#include <stdlib.h>

int chrlength(char *s){
	int i = 0;
	while(*s++)
		i++;
	return i;
}

int stcpy(char *s, char *p){
	while(*p){
		*s++ = *p++;
	}
	*s = '\0';
}

int stcmparison(char *ch1, char *ch2){
	int i = 1;
	char cha1, cha2;
	while((cha1 = (*ch1++)) && (cha2 = (*ch2++))){
		if(cha1 > cha2){
			return 1;
		}
		else if(cha1 < cha2)
			return -1;
	}
	
	if(!cha1)
		cha2 = (*ch2++);
	if(cha1)
		return 1;
	if(cha2)
		return -1;
	return 0;
}

int strcate(char *s1, char *s2){
	while(*s1++);
	s1--;
	while(*s2)
		(*s1++) = (*s2++);
	*s1 = '\0';
}

int main(){
	char *name, *cp, *str1, *str2, strc[30], str2c[30], *copy;
	printf("\nEnter string\n");
	scanf("%[^\n]%*c", strc);
	name = strc;
	printf("String length: %d\n", chrlength(name));

	printf("\nEnter string to be copied:\n");
	scanf("%[^\n]%*c", str2c);
	cp = str2c;
	copy = (char *) malloc(sizeof(char) * chrlength(cp));
	stcpy(copy, cp);
	printf("\nCopied string: %s\n", copy);
	printf("\nEnter str1 and str2: \n");
	scanf("%[^\n]%*c%[^\n]%*c", strc, str2c);
	str1 = strc;
	str2 = str2c;
	printf("String comparison: %d\n", stcmparison(str1, str2));

	printf("\nEnter string1 and string2: \n");
	scanf("%[^\n]%*c%[^\n]%*c", strc, str2c);
	str1 = strc;
	str2 = str2c;
	strcate(str1, str2);
	printf("\nConcatenated string: %s\n", str1);
}
