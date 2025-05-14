#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

struct node *createNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void printList(struct node *head)
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

struct node *createList(struct node *head, int n1)
{
    int val;
    for (int i = 0; i < n1; i++)
    {
        printf("Enter node data in sorted way for insertion\n");
        scanf("%d", &val);
        struct node *new_node = createNode(val);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            struct node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    return head;
}

void mergeList()
{
    struct node *list1 = head1;
    struct node *list2 = head2;
    struct node *res = (struct node *)malloc(sizeof(struct node *));
    struct node *dummy = res;

    while(list1 != NULL && list2 != NULL){
        if(list1->data > list2 -> data){
            dummy->next = list2;
            list2 = list2->next;
        }
        else{
            dummy->next = list1;
            list1 = list1->next;
        }
        dummy = dummy->next;
    }

    if(list1)
        dummy->next = list1;
    if(list2)
        dummy->next = list2;
    
    printList(res -> next);
}

int main()
{
    int n1, n2;
    printf("Enter size of list 1 : \n");
    scanf("%d", &n1);
    head1 = createList(head1, n1);
    printf("Linked List 1 : \n");
    printList(head1);

    printf("Enter size of list 2 : \n");
    scanf("%d", &n2);
    head2 = createList(head2, n2);
    printf("Linked List 2 : \n");
    printList(head2);

    mergeList();
    // void merg   eList()
    return 0;
}