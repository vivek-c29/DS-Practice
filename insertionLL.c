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

void insertAtStart()
{
    int val;
    printf("Enter data to be inserted at start : \n");
    scanf("%d", &val);
    if (head == NULL)
    {
        struct node *new_node = createNode(val);
        new_node->next = head;
        head = new_node;
        printf("%d inserted succesfully at the start.\n", val);
    }
}

void insertAtEnd()
{
    int val;
    printf("Enter data to be inserted at end : \n");
    scanf("%d", &val);
    if (head == NULL)
        insertAtStart();
    else
    {
        struct node *ptr = head;
        struct node *new_node = createNode(val);
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
        printf("%d inserted succesfully at th end.\n", val);
    }
}

void insertAfterSpecific()
{
    int val, new_data;
    printf("Enter the data after which new node has to be inserted : \n");
    scanf("%d", &val);
    printf("Enter new data value which has to be inserted : \n");
    scanf("%d", &new_data);

    struct node *new_node = createNode(new_data);
    if (head == new_node)
        head = new_node;
    else
    {
        struct node *temp = head;
        while (temp->data != val)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        printf("%d inserted succesfully after %d\n", new_data, val);
    }
}

void insertBeforeSpecific()
{
    int val, new_data;
    printf("Enter the data before which new node has to be inserted : \n");
    scanf("%d", &val);
    printf("Enter new data value which has to be inserted : \n");
    scanf("%d", &new_data);
    struct node *new_node = createNode(new_data);
    if (head == NULL)
        head = new_node;
    else
    {
        struct node *p, *q;
        p = head;
        q = NULL;
        while (p->data != val)
        {
            q = p;
            p = p->next;
        }
        new_node->next = q->next;
        q->next = new_node;
        printf("%d inserted succesfully before %d\n", new_data, val);
    }
}

void deleteAtStart()
{
    if (head == NULL)
    {
        printf("Cannot delete.List is Empty!\n");
    }
    else
    {
        struct node *first = head;
        head = head->next;
        printList();
        printf("%d deleted successfully!.\n", first->data);
        free(first);
    }
}

void deleteAtEnd()
{
    struct node *p = head;
    struct node *q;
    q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printList();
    printf("%d deleted succesfully from the end.\n", p->data);
    free(p);
}

void deleteAfterSpecific()
{
    struct node *p = head;
    int val;
    printf("Enter the node data after which node has to be deleted : \n");
    scanf("%d", &val);
    while (p->data != val)
    {
        p = p->next;
    }
    struct node *p_next = p->next;
    p->next = p_next->next;
    printList();
    printf("After to %d,%d deleted succesfully", val, p_next->data);
    free(p_next);
}

void deleteBeforeSpecific()
{
    struct node *p;
    struct node *q, *r;
    int val;
    printf("Enter the node data before which node has to be deleted : \n");
    scanf("%d", &val);
    r = head->next;
    q = head;
    p = NULL;
    while (r->data != val)
    {
        p = q;
        q = r;
        r = r->next;
    }
    p->next = r;
    printList();
    printf("Before to %d,%d deleted succesfully.\n", val, q->data);
    free(q);
}

void searchTarget()
{
    int val;
    printf("Enter the target data : \n");
    scanf("%d", &val);
    struct node *p = head;
    while (p!=NULL)
    {
        if (p->data == val)
        {
            printf("Target data %d found in LinkedList\n", val);
            return;
        }
        
        p = p->next;
    }
    
        {
            printf("Target data %d not found in LinkedList\n", val);
        }
}
int main()
{

    // printList();
    // insertAtStart();
    // printList();
    // insertAtEnd();
    // printList();
    // insertAfterSpecific();
    // printList();
    // insertBeforeSpecific();
    // // printList();
    // insertAtEnd();
    // insertAtEnd();
    // printList();
    // deleteAtStart();
    // deleteAtEnd();
    // // deleteAfterSpecific();
    // // deleteBeforeSpecific();
    // searchTarget();

    int choice1,choice2,flag;
    flag = 1;
    
    while(flag==1){
        printf("Enter 1 for insertion\nEnter 2 for deletion\nEnter 3 for searching\nEnter 4 for display\nEnter 5 for exit\n");
        scanf("%d",&choice1);
        switch(choice1){
            case 1:
                printf("Enter 1 for insertion at start\nEnter 2 for insertion at End\nEnter 3 for inertion after specific node\nEnter 4 for insertion before specific node\n");
                scanf("%d",&choice2);
                switch(choice2){
                    case 1:
                        insertAtStart();
                        break;
                    case 2:
                        insertAtEnd();
                        break;
                    case 3:
                        insertAfterSpecific();
                        break;
                    case 4:
                        insertBeforeSpecific();
                        break;
                    default:
                        printf("Invalid choice.!\n");
                        break;
                }
                break;
            case 2:
                printf("Enter 1 for deletion at start\nEnter 2 for deletion at End\nEnter 3 for deletion after specific node\nEnter 4 for deletion before specific node\n");
                scanf("%d",&choice2);
                switch(choice2){
                    case 1:
                        deleteAtStart();
                        break;
                    case 2:
                        deleteAtEnd();
                        break;
                    case 3:
                        deleteAfterSpecific();
                        break;
                    case 4:
                        deleteBeforeSpecific();
                        break;
                    default:
                        printf("Invalid choice.!\n");
                        break;
                }
                break;
            case 3:
                searchTarget();
                break;
            case 4:
                printList();
                break;
            case 5:
                flag=0;
                break;
            default:
                printf("Invalid choice!");
                break;
            
        }
    }

    return 0;
}