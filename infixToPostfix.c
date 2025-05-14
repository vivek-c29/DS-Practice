#include <stdio.h>
#include <stdlib.h>

#define MAX 100
char stack[MAX], top = -1;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

void convert(char *s, char *res)
{
    int j = 0;
    for (int i = 0; s[i]; i++)
    {
        char c = s[i];
        if (isalnum(c))
        {
            res[j++] = c;
        }
        else if (c == '(')
            stack[++top] = c;
        else if (c == ')')
        {
            while (stack[top] != '(' && !(top == -1))
            {
                res[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 && prec(c) <= prec(stack[top]))
            {
                res[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while(!(top==-1)){
        res[j++] = stack[top--];
    }
    res[j]='\0';
    printf("Postfix expression is %s\n",res);
}

int main()
{
    char infix[100];
    char postfix[100];
    printf("Enter expression : \n");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("%s",postfix);
    return 0;
}