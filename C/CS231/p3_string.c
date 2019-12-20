/* Write a menu-driven program to implement the following string operations with-
out using library functions :
	a) String length
	b) String concatenation
	c) String copy
	d) String comparison
	e) Substring search and replacement
	f) Count the number of vowels,consonants and number of words in a sentence */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sub_str(char *, char *);
int str_len(char[]);
int str_cmp(char[], char[]);
int str_replace(char[], char[], char[], char[]);
int str_concat(char[], char[]);
int str_cpy(char[], char[]);
int no_of_vowels(char[]);

int main()
{
	int i, quit = 0, ch;
	char str[50], str2[50], str3[50] = "", sub[50], replace[50], result[50] = "";
	printf("Enter string\n");
	scanf("%[^\n]%*c", str);
	while(!quit)
	{
		printf("Menu\n1.strlen\n2.strcmp\n3.strcpy\n4.strreplace\n5.countvowels\n6.strcat\n7.quit\n");
		scanf("%d%*c", &ch);
		switch(ch)
		{
			case 1:
				printf("The length of the string is %d\n", str_len(str));
				break;

			case 2:
				printf("Enter string to compare\n");
				scanf("%[^\n]%*c", str2);
				printf("Result of comparison: %d\n", str_cmp(str, str2));
				break;

			case 3:
				str_cpy(str, str3);
				break;

			case 4:
				printf("Enter substring to search\n");
				scanf("%[^\n]%*c", sub);
				printf("Enter replacement string\n");
				scanf("%[^\n]%*c", replace);
				replacer(str, sub, replace, result);
				printf("%s\n", result);
				break;

			case 5:
				no_of_vowels(str);
				break;

			case 6:
				printf("Enter string to concatenate\n");
				scanf("%[^\n]%*c", str2);
				str_concat(str, str2);
				printf("Concatenated string: \n%s\n", str);
				break;

			case 7:
				quit = 1;
				break;
		}
	}
}


int str_len(char ch[])
{
	int len = 0, i = 0;
	while(ch[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

int str_cmp(char s1[], char s2[])
{
	int i = 0;
	while((s1[i] == s2[i]) && s1[i] != '\0')
	{i++;}
	if(s1[i] < s2[i])
		return -1;
	else if(s1[i] > s2[i])
		return 1;
	else
		return 0;
}

int replacer(char str[], char pattern[], char key[], char output[])
{
        int i, j, k, l;
        char temp[100];
        for (i = 0, l = 0; str[l] != '\0'; ) 
		{
                if (str[l] == pattern[0]) 
				{
                        j = 0;
                        k = 0;
                        while (str[l] != '\0' && str[l] == pattern[j]) 
						{
                                temp[k] = str[l];
                                ++k;
                                ++l;
                                ++j;
                        }
                        temp[k] = '\0';
                        if (pattern[j] == '\0') 
						{
                                for (k = 0; key[k] != '\0'; ++k)
                                        output[i++] = key[k];
                        } else 
						{
                                for (k = 0; temp[k] != '\0'; ++k)
                                        output[i++] = temp[k];
                        }
                } else 
				{
                        output[i++] = str[l++];
                }
        }
        output[i] = '\0';
        return output;
}




int str_cpy(char source[], char target[])
{
	int i = 0;
	printf("Before copying, string3 = %s, string1 = %s\n", target, source);
	while(source[i] != '\0')
	{
		target[i] = source[i];
		i++;
	}
	target[i] = '\0';
	printf("After copying, string3 = %s, string1 = %s\n", target, source);
}

int str_concat(char s1[], char s2[])
{
	int i, j;
	for(i = 0; s1[i] != '\0'; i++);
    	for(j = 0; s2[j] != '\0'; ++j, ++i)
    	
		{
        	s1[i] = s2[j];
    	}
    	s1[i] = '\0';
}


int no_of_vowels(char s1[])
{
	int i = 0, nv = 0, nw = 1, nc = 0;
	while(s1[i] != '\0')
	{
		switch(s1[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				nv++;
				break;
			case ' ':
				nw++;
				break;

			default:
				if((s1[i] > 'a' && s1[i] < 'z') || (s1[i] > 'A' && s1[i] < 'Z'))
				{
					nc++;
				}
		}
		i++;
	}
	printf("No of vowels = %d, consonants = %d, words = %d\n", nv, nc, nw);
	return 0;
}
