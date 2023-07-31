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
node *deleteAtBegining(node *head){
    node *temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
node *deleteAtEnd(node *head){
    node *temp=head;
    node *ptr;
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    ptr=temp->next->next;
    temp->next=NULL;
    free(ptr);

    return head;
}
node *deleteFromMiddle(node *head ,int position){
    node *temp=head;
    node *ptr;
    for (int i=0;i<position;i++){
        if (temp->next!=NULL){
            temp=temp->next;
        }
    }
    ptr=temp->next;
    temp->next=temp->next->next;
    free(ptr);
    return head;
}
int main(){
    node *head,*newnode,*temp;
    head=NULL;
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
    head=deleteAtBegining(head);
    printf("After deleting the begining node\n");
    treversal(head);
    head=deleteAtEnd(head);
    printf("After deleting the last node\n");
    treversal(head);
    printf("Which position of value you want to delete : ");
    int position;
    scanf("%d",&position);
    position=position-1;
    head=deleteFromMiddle(head,position);
    printf("After deleting a node from middle\n");
    treversal(head);
    return 0;
}