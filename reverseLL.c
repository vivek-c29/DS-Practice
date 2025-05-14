// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *head = NULL;

// struct node *createNode(int data)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));
//     ptr->data = data;
//     ptr->next = NULL;
//     return ptr;
// }

// void printList()
// {
//     struct node *ptr = head;
//     printf("Linked List is : \n");
//     while (ptr != NULL)
//     {
//         printf("%d -> ", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("NULL \n");
// }

// void insertAtEnd()
// {
//     int val;
//     printf("Enter data to be inserted at end : \n");
//     scanf("%d", &val);
//     struct node *new_node = createNode(val);
//     if (head == NULL)
//         head = new_node;
//     else
//     {
//         struct node *ptr = head;
//         while (ptr->next != NULL)
//         {
//             ptr = ptr->next;
//         }
//         ptr->next = new_node;
//         new_node->next = NULL;
//         printf("%d inserted succesfully at th end.\n", val);
//     }
// }

// struct node *reverseList(){
//     struct node *prev,*curr,*next;
//     curr = head;
//     prev = NULL;
//     next = NULL;

//     while(curr != NULL){
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }

//     return prev;
// }

// int main()
// {

//     insertAtEnd();
//     insertAtEnd();
//     insertAtEnd();
//     printList();
// head = reverseList();
// printList();
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;     // Save next node
        curr->next = prev;     // Reverse pointer
        prev = curr;           // Move prev forward
        curr = next;           // Move curr forward
    }

    return prev; // New head
}

// Main
int main() {
    struct Node* head = NULL;

    // Create list: 1 -> 2 -> 3 -> NULL
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Original list:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}

