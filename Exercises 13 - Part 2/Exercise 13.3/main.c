#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    struct BST *left;
    int data;
    struct BST *right;
}BSTNode;

BSTNode* newNode(int value);
BSTNode* insertNode(BSTNode *root, int value);
void inorder(BSTNode *root);
void preorder(BSTNode *root);
void postorder(BSTNode *root);
BSTNode* minValue(BSTNode *root);
BSTNode* deleteNode(BSTNode *root, int key);

int main(){
    int i, number, n; //Counter i
    BSTNode *root=NULL;
    printf("Enter how many numbers you'll enter in the tree\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter a number\n");
        scanf("%d", &number);
        root=insertNode(root,number);
    }
    printf("Inorder print:\n");
    inorder(root);
    printf("\nPreorder print:\n");
    preorder(root);
    printf("\nPostorder print:\n");
    postorder(root);
    printf("\nEnter the number you want to delete\n");
    scanf("%d", &number);
    root=deleteNode(root,number);
    printf("New order of the tree:\n");
    inorder(root);
    return 0;
}

BSTNode* newNode(int value){
    BSTNode *new=malloc(sizeof(BSTNode));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

BSTNode* insertNode(BSTNode *root, int value){
    if(root==NULL)
        return newNode(value);
    if(value<root->data)
        root->left=insertNode(root->left,value);
    else if(value>root->data)
        root->right=insertNode(root->right,value);
    return root;
}

void inorder(BSTNode *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(BSTNode *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BSTNode *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

BSTNode* minValue(BSTNode *root){
    BSTNode *current=root;
    while(current&&current->left!=NULL)
        current=current->left;
    return current;
}

BSTNode* deleteNode(BSTNode *root, int key){
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if(key>root->data)
        root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            BSTNode *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            BSTNode *temp=root->left;
            free(root);
            return temp;
        }
        BSTNode *temp=minValue(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}