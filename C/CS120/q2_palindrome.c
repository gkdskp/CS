/* A palindrome is defined as a word, phrase, or sequence that reads the same
backwards as forwards. In this problem you are given a number N and are
asked to check if it is a palindrome or not an example of a palindrome number
would be 12321.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num, rev = 0, temp;

    scanf("%d", &num);
    temp = num;


    while(num){
        rev = rev*10 + num%10;
        num = num/10;
    }
    
    if(temp == rev)
        printf("%d", 1);
    else
        printf("%d", 0);
    return 0;
}