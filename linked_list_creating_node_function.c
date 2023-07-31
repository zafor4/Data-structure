#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;
void treversal(node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
// void *function(node *head){
//     node *newnode,*temp;
//     newnode =(node *)malloc(sizeof(node));
//     printf("Enter the data : ");
//     scanf("%d",&newnode->next);
//     if (head==0){
//         head=temp=newnode;
//         temp=newnode;

//     } 
//     else {
//         temp->next=newnode;
//         temp = newnode;
//     }

// }
int main(){
    node *head,*newnode,*temp;
    head=0;
    int choice;
    while(choice){
        newnode=(node *)malloc(sizeof(node));
        printf("Enter the data\n");
        scanf("%d",&(newnode->data));
        newnode->next=0;
        if (head==0){
            head=temp=newnode;
            temp=newnode;
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue(0,1)\n");
        scanf("%d",&choice);
    }
    printf("Data stored are: \n");
    treversal(head);
    return 0;
}