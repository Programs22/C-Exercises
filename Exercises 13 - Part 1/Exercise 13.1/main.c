#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    char character;
    struct Node *link;
}Node;

typedef Node *NodePtr;

void insert(NodePtr *head, int n, char c);
void printList(NodePtr head);

int main(){
    int i, number, n; // Counter i
    char c;
    NodePtr head=NULL;
    printf("Enter how many elements will be in the list\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the number and character you want to enter\n");
        scanf("%d", &number);
        scanf(" %c", &c);
        insert(&head,number,c);
    }
    printList(head);
    printf("NULL");
    return 0;
}

void insert(NodePtr *head, int n, char c){
    NodePtr new;
    NodePtr move=*head;
    new=malloc(sizeof(Node));
    if(new!=NULL){
        new->number=n;
        new->character=c;
        new->link=NULL;
    }
    if(move==NULL){
        new->link=*head;
        *head=new;
    }
    else{
        while(move->link!=NULL)
            move=move->link;
        move->link=new;
    }
}

void printList(NodePtr head){
    if(head==NULL)
        printf("The list is empty\n");
    if(head->link==NULL){
        printf("|%d||%c|->", head->number, head->character);
        return;
    }
    else{
        printList(head->link);
        printf("|%d||%c|->", head->number, head->character);
    }
}
