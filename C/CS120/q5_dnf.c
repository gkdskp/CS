/* The Dutch national flag problem (DNF) is a computer science programming
problem proposed by Edsger Dijkstra. The flag of the Netherlands consists of
three colors: red, white and blue. Given balls of these three colors arranged
randomly in a line (the actual number of balls does not matter), the task is
to arrange them such that all balls of the same color are together and their
collective color groups are in the correct order.
Given an array arr of size N. The array arr has only 0’s,1’s and 2’s. Your
duty is to sort the array arr.
For example:
Given arr:[1,0,1,2,0,2]
The output is [0,0,1,1,2,2,] */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int size, i = 0, ar[1000000], j =0, temp, z = 0, o = 0, t = 0;
    scanf("%d", &size);
    for(i =0; i < size; i++)
        scanf("%d", &ar[i]);
    
    for(i = 0; i < size; i++){
        if(ar[i] == 0) z++;
        if(ar[i] == 1) o++;
        if(ar[i] == 2) t++;
    }
    
        for(i = 0; i < z; i++)
            printf("%d", 0);
        for(i = 0; i < o; i++)
            printf("%d", 1);
        for(i = 0; i < t; i++)
            printf("%d", 2);
    
    return 0;
}
