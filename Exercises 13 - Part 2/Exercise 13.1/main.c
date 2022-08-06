#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

typedef struct Stack{
    char info;
    struct Stack *next;
}Node;

typedef Node *NodePtr;

void push(NodePtr *top, char c);
char pop(NodePtr *top);
int isEmpty(NodePtr top);

int main(){
    char string[size], new[size];
    int i; // Counter
    NodePtr top=NULL;
    printf("Enter a string\n");
    gets(string);
    for(i=0;i<strlen(string);i++){
        push(&top,string[i]);
    }
    i=0;
    while(!isEmpty(top)){
        new[i]=pop(&top);
        i++;
    }
    new[i]='\0';
    printf("The inverted string is: %s\n", new);
    return 0;
}

void push(NodePtr *top, char c){
    NodePtr new;
    new=malloc(sizeof(Node));
    new->info=c;
    new->next=*top;
    *top=new;
}

char pop(NodePtr *top){
    NodePtr temp;
    char info;
    temp=*top;
    info=(*top)->info;
    *top=(*top)->next;
    free(temp);
    return info;
}

int isEmpty(NodePtr top){
    return top==NULL;
}
