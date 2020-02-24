/*
Write a Java Program to determine whether a given matrix is an identity matrix 
*/

import java.util.Scanner;

class Matrix{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n, flag = 0;

        System.out.println("Enter order of matrix, n:");
        n = sc.nextInt();

        int[][] mat = new int[n][n]; 

        System.out.println("Enter matrix elements: ");
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mat[i][j] = sc.nextInt();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i == j && mat[i][j] != 1) flag = 1;
                else if(i != j && mat[i][j] != 0) flag = 1;

        if(flag == 1)
            System.out.println("Not an identity matrix");
        else
            System.out.println("Identity matrix");
    }
}