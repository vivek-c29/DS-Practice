#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void printList()
{
    struct node *ptr = head;
    printf("Linked List is : \n");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n");
}

void insertAtEnd()
{
    int val;
    printf("Enter data to be inserted at end : \n");
    scanf("%d", &val);
    struct node *new_node = createNode(val);
    if (head == NULL)
        head = new_node;
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
        printf("%d inserted succesfully at th end.\n", val);
    }
}

void sort()
{
    struct node *i, *j;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if(i->data >= j-> data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{

    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    printList();
    sort();
    printList();
    return 0;
}