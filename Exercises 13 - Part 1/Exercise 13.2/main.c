#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    struct Node *link;
}Node;

typedef Node *NodePtr;

void insert(NodePtr *head, int n);
void printList(NodePtr head);
void sortAscending(NodePtr *head);
void sortDescending(NodePtr *head);
int delete(NodePtr *head, int n);

int main(){
    int i, number, n, choice; // Counter i
    NodePtr head=NULL;
    printf("Enter how many elements will be in the list\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the number you want to enter\n");
        scanf("%d", &number);
        insert(&head,number);
    }
    printList(head);
    printf("Enter 1 if you want to sort it in ascending order, 2 to sort it in descending order\n");
    scanf("%d", &choice);
    if(choice==1)
        sortAscending(&head);
    else
        sortDescending(&head);
    printList(head);
    printf("Enter the node you want to delete\n");
    scanf("%d", &number);
    if(delete(&head,number))
        printf("Node deleted\n");
    else
        printf("Node not in the list\n");
    printList(head);
    return 0;
}

void insert(NodePtr *head, int n){
    NodePtr new;
    NodePtr move=*head;
    new=malloc(sizeof(Node));
    if(new!=NULL){
        new->number=n;
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
    else{
        while(head!=NULL){
            printf("|%d|->", head->number);
            head=head->link;
        }
        printf("NULL\n");
    }
}

void sortAscending(NodePtr *head){
    NodePtr move;
    int swap, temp;
    do{
        swap=0;
        move=*head;
        while(move->link!=NULL){
            if(move->number>move->link->number){
                temp=move->number;
                move->number=move->link->number;
                move->link->number=temp;
                swap=1;
            }
            move=move->link;
        }
    }while(swap);
}

void sortDescending(NodePtr *head){
    NodePtr move;
    int swap, temp;
    do{
        swap=0;
        move=*head;
        while(move->link!=NULL){
            if(move->number<move->link->number){
                temp=move->number;
                move->number=move->link->number;
                move->link->number=temp;
                swap=1;
            }
            move=move->link;
        }
    }while(swap);
}

int delete(NodePtr *head, int n){
    NodePtr previous, current, temp;
    if(n==(*head)->number){
        temp=*head;
        *head=(*head)->link;
        free(temp);
        return n;
    }
    else{
        previous=*head;
        current=(*head)->link;
        while(current!=NULL&&current->number!=n){
            previous=current;
            current=current->link;
        }
        if(current!=NULL){
            temp=current;
            previous->link=current->link;
            free(temp);
            return n;
        }
        else
            return 0;
    }
}