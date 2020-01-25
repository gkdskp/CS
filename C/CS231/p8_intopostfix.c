/* Write a program to convert an infix expression to postfix using stack */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
char Stack[MAX], expr[MAX], outexpr[MAX], temp;
int head = -1;

int push(char val)
{
    if(head == MAX-1)
        printf("Stack full\n");
    else
    {
        Stack[++head] = val;
    }
}

int pop()
{
    if(head == -1)
        return -1;
    else
        return Stack[head--];
}

int peek()
{
    return Stack[head];
}

int priority(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isOperand(char op)
{
    return (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z');
}

int convert(char expr[])
{
    int i = 0, j = 0;
    while(expr[i])
    {
        if(expr[i] == '(')
        {
            push(expr[i]);
        }
        else if(expr[i] == ')')
        {
            while(expr[i] != '(' && (temp = pop()) != -1)
            {
                if(temp != '(') outexpr[j++] = temp;
            }
        }
        else if(!isOperand(expr[i]))
        {
            while(priority(expr[i]) <= priority(peek()))
            {
                temp = pop();
                if(temp == -1)
                    break;
                if(temp != '(') outexpr[j++] = temp;
            }
            push(expr[i]);
        }
        else
        {
            outexpr[j++] = expr[i];
        }
        ++i;
    }
    outexpr[j] = '\0';
}

int main()
{
    printf("Enter infix expression\n");
    scanf("%[^\n]%*c", expr);
    convert(expr);
    printf("Corresponding posfix expression\n%s\n", outexpr);
}