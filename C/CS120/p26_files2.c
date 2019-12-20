/* To find the no. of words and sentences in a text file */

#include <stdio.h>

void main(){
	FILE *fp;
    int w = 0, s = 0;
    char pr, ch;

	printf("\nMake sure the text file is saved as file.txt\n");
    fp = fopen("file.txt", "r");
	ch = getc(fp);
	pr = ch;

	while(ch != EOF){
		if((ch == ' ' || ch == '.' || ch == '\t' || ch == '\n')
		&& (pr != ' ' && pr != '.' && pr != '\n' && pr !='\t'))
			w++;
		if(ch == '.' && pr != '.')
			s++;
		pr = ch;
		ch = getc(fp);
	}

	printf("\nNumber of words: %d",w);
	printf("\nNumber of sentences: %d\n",s);
	fclose(fp);
}

