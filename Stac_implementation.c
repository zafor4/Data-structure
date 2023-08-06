#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *top=0;
void push(int data){
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}
display(){
    node *temp;
    temp=top;
    if (top==NULL){
        printf("Underflow condition\n");
    }
    while (temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
}
void peek(){
    if (top==0){
        printf("there is no data in the stac\n");
    }
    printf("%d",top->data);
}
void pop(){
    node *temp;
    temp=top;
    if (top==NULL){
        printf("Underflow\n");
    }
    printf("The poped element is \n",top->data);
    top=top->link;
    free(temp);
}