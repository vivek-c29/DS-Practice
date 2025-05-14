#include <stdio.h>
#include <stdlib.h>

#define MAX 50
char stack[MAX], top = -1;

void push(char ch)
{
    if (!(top == (MAX - 1)))
    {
        stack[++top] = ch;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

char pop(){
    if(!(top==-1)){
        return stack[top--];
    }
}

char peek(){
    return stack[top];
}

int isMatching(char a,char b){
    if((a=='(' && b==')') || a=='[' && b==']' || a=='{' && b=='}')
        return 1;
    
    return 0;
}

int checkParanthesis(char *s){
    for(int i=0;s[i];i++){
        if(s[i]=='(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        }
        else if(s[i]==')' || s[i] == ']' || s[i] == '}'){
            if(top==-1 || !isMatching(stack[top],s[i])){
                return 0;
            }
            char ch = pop();

        }
    }
    return top==-1;
}

int main()
{
    char exp[MAX];
    printf("Enter input string : \n");
    scanf("%s",exp);
    int res = checkParanthesis(exp);
    if(res){
        printf("Given string is balanced!\n");
    }
    else{
        printf("Given String is not balanced!\n");
    }
    return 0;
}