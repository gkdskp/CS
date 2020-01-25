/* Write a menu-driven program for the following
    a) Evaluation of a postfix expression 
    b) Evaluation of a prefix expression */

#include <stdio.h>
#include <string.h>

#define MAX 50
int Stack[MAX], head = -1;

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

int isOperand(char op)
{
    return (op >= '0' && op <= '9');
}

int postEval(char exp[])
{
    int i = 0, val1, val2;
    while(exp[i])
    {
        if(isOperand(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            val1 = pop();
            val2 = pop();
            switch (exp[i])
            {
            case '+':
                push(val2 + val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            default:
                break;
            }
        }
        ++i;
    }
    return Stack[head];
}

int preEval(char exp[])
{
    int i = strlen(exp) - 1, val1, val2;
    while(i >= 0)
    {
        if(isOperand(exp[i]))
        {
            push(exp[i] - '0');
        }
        else 
        {
            val1 = pop();
            val2 = pop();

            switch(exp[i])
            {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
            }
        }
        --i;
    }
    return Stack[head];
}

int main()
{
    char exp[MAX];
    int result, ch;

    printf("1. Postfix evaluation\n"
    "2. Prefix evaluation\n");
    scanf("%d%*c", &ch);
    printf("Enter expression:\n");
    scanf("%[^\n]%*c", exp);
    result = (ch == 1)? postEval(exp): preEval(exp);
    printf("%d\n", result);
}