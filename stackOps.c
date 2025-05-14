#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int top = -1;
int stack[MAX];
int isFull()
{
    if (top == (MAX - 1))
    {
        printf("Stack overflow\n");
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return 1;
    }
    return 0;
}

void push(int val)
{
    if (!isFull())
        stack[++top] = val;
    else
    {
        printf("Stack overflow.Cannot push %d\n", val);
    }
}

void pop(){
    if(!isEmpty()){
        int data = stack[top];
        top--;
        printf("Popped : %d\n",data);
    
    }
    else{
        printf("Stack Underflow.Cannot Pop!\n");
    }
}

void peek()
{
    if (isFull())
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        printf("Top Element : %d\n", stack[top]);
    }
}

void display(){
    if(isEmpty()){
        printf("Stack Underflow.!\n");

    }

    else{
        printf("Stack...\n");
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    printf("Enter data to be pushed : \n");
    scanf("%d", &n);
    push(n);
    push(-8);
    push(105);

    push(2);
    display();
    peek();
    pop();
    pop();
    return 0;
}