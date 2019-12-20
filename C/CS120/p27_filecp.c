/* Using command line arguments copy the content of one text file to 
another after converting all lower case letters to upper case */

#include <stdio.h>
#include <string.h>

#define file1 argv[1]
#define file2 argv[2]

char toUpper(char);

int main(int argc,char *argv[]){
        FILE *f1, *f2;
        char ch;

        if(argc == 1){
                printf("\nSpecify the target file and file to be copied as "
                "command line arguments\n");
                return 1;
        }

        f1 = fopen(file1, "w");
        f2 = fopen(file2, "r");
        printf("\n");
        while((ch = getc(f2)) != EOF){
                ch = toUpper(ch);
                putc(ch, f1);
        }
        fclose(f1);
        fclose(f2);

        f1=fopen(file1, "r");
        printf("%s: \n", argv[1]);

        while((ch = getc(f1)) != EOF)
                putchar(ch);
        printf("\n");
}

char toUpper(char c){
        if(c >= 'a' && c <= 'z')
                c = 'A' + (c - 'a');
        return c;
}
