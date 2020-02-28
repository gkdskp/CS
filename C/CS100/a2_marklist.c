/*
Write a program to read the rollno, name and 4 marks of a set N students into an
array of structure. Prepare a rank list ,based on the total marks, of students
passed in the examination . If the total marks of two students are same they are
alloted the same rank. In order to pass the exam a student must get a minimum of
40% of marks in each subject.
*/

#include <stdio.h>

struct Student
{
    int rno;
    int marks[4];
    int total_marks;
    char name[30];
    int rank;
    int pass;
} s[100], temp;

int main ()
{
    int N, i, j, rank, total;
    printf ("\nEnter number of students\n");
    scanf ("%d", &N);

    // Reading the array elements
    for (i = 0; i < N; i++)
    {
        printf ("\nEnter details of Student%d\n", i + 1);
        scanf ("%d%s%d%d%d%d", &s[i].rno, s[i].name, &s[i].marks[0], &s[i].marks[1], &s[i].marks[2],
               &s[i].marks[3]);
        for (j = 0; j < 4; j++)
            s[i].total_marks += s[i].marks[j];
    }

    // Bubble sort
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (s[j].total_marks < s[j + 1].total_marks)
            {
                temp = s[j + 1];
                s[j + 1] = s[j];
                s[j] = temp;
            }
        }
    }

    // Checking if a student passed the exam, Marks are assumed to be in 50
    for (i = 0; i < N; i++)
    {
        s[i].pass = 1;
        for (j = 0; j < 4; j++)
        {
            if (s[i].marks[j] * 2 < 40) s[i].pass = 0;
        }
    }

    // Generating ranks
    rank = 1;
    total = s[0].total_marks;
    for (i = 0; i < N; i++)
    {
        if (s[i].pass)
        {
            if (s[i].total_marks == total)
                s[i].rank = rank;
            else
                s[i].rank = ++rank;
            total = s[i].total_marks;
        }
    }

    // Printing the array elements
    printf ("\nRank List\n------------\n");
    printf ("Rank\tName\tRoll No\tTotal Marks\n");
    for (i = 0; i < N; i++)
    {
        if (s[i].pass)
            printf ("%d\t%s\t%d\t%d\n", s[i].rank, s[i].name, s[i].rno, s[i].total_marks);
        else
            printf ("FAIL\t%s\t%d\t%d\n", s[i].name, s[i].rno, s[i].total_marks);
    }
}
