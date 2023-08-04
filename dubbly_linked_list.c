#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head,*newnode;
void create_node(){
    head=0;
    node *temp;
    int choice;
    while(choice){
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if (head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    printf("Do You want to continue(1 or 0)\n");
    scanf("%d",&choice);
    }
} 
void treversal(node *ptr){
    printf("Information stored in the link list are: \n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){  
    create_node();
    treversal(head);
    return 0;
}