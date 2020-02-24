/*
Write a function for checking whether a number is a fibonaccii number or not. Using this
function write a program for displaying the fibonaccii numbers in a m x n martrix.
*/

#include <stdio.h>

int is_fibonacci(int);

int main()
{
    int m, n, i = 0, j = 0, k = 0, fib_array[20][20];

    //Reading the order of the matrix
    printf("\nEnter order of the matrix in mxn format\n");
    scanf("%dx%d", &m, &n);
    printf("\n");


    fib_array[0][0] = 1;

    //Populating the array with Fibonacci numbers
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(fib_array[i][j])
                continue;
            while(!is_fibonacci(++k));
            fib_array[i][j] = k;
            k++;
        }
    }

    //Displaying the array
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", fib_array[i][j]);
        }
        printf("\n");
    }
}

int is_fibonacci(int n)
{
    int a = 1, b = 1, temp, is_fib = 1;
    while(a < n)
    {
        temp = a;
        a = a + b;
        b = temp;
    }
    is_fib = (n == a)? 1: 0;
    return is_fib;
}
