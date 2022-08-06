#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    struct BST *left;
    int data;
    int count; // The number of times this element is present in the tree
    struct BST *right;
}BSTNode;

typedef BSTNode *BSTNodePtr;

void insertNode(BSTNodePtr *root, int value);
void inorder(BSTNodePtr root);
void preorder(BSTNodePtr root);
void postorder(BSTNodePtr root);

int main(){
    int i, number, n; //Counter i
    BSTNodePtr root=NULL;
    printf("Enter how many numbers you'll enter in the tree\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter a number\n");
        scanf("%d", &number);
        insertNode(&root,number);
    }
    printf("Inorder print:\n");
    inorder(root);
    printf("\nPreorder print:\n");
    preorder(root);
    printf("\nPostorder print:\n");
    postorder(root);
    return 0;
}

void insertNode(BSTNodePtr *root, int value){
    if(*root==NULL){
        *root=malloc(sizeof(BSTNode));
        (*root)->data=value;
        (*root)->count=1;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else{
        if(value<(*root)->data)
            insertNode(&((*root)->left),value);
        else if(value>(*root)->data)
            insertNode(&((*root)->right),value);
        else
            ((*root)->count)++;
    }
}

void inorder(BSTNodePtr root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d(%d) ",root->data, root->count);
        inorder(root->right);
    }
}

void preorder(BSTNodePtr root){
    if(root!=NULL){
        printf("%d(%d) ",root->data, root->count);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BSTNodePtr root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d(%d) ",root->data, root->count);
    }
}