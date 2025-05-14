#include<stdio.h>
#include<Stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val){
    struct node *ptr = (struct node *)malloc(sizeof(struct node ));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node *buildTree(){
    int data;
    printf("Enter data (-1 for no node) : \n");
    scanf("%d",&data);
    if(data==-1)
        return NULL;
    struct node *new = createNode(data);
    printf("Enter left child for %d\n",data);
    new->left = buildTree();
    printf("Enter right child for %d\n",data);
    new->right = buildTree();
    return new;
}

void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}

int main(){

    struct node *root = NULL;
    root = buildTree();
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}