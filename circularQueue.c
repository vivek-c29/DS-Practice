#include <stdlib.h>
#include <stdio.h>

#define SIZE 5
int front = -1;
int rear = -1;
int queue[SIZE];

int isFull()
{
    return (front == (rear + 1) % SIZE);
}

int isEmpty()
{
    return (front == -1);
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue overflow!\n");
        return;
    }
    else
    {
        printf("Deleted : %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    int i = front;
    printf("Queue : ");
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();

    return 0;
}