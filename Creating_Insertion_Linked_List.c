#include<stdio.h>
# include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;
void travarsal(node *ptr){
    while (ptr!=NULL){
        printf("element = %d\n",ptr->data);
        ptr=ptr->next;
    }
}

node *insertAtEnd(node *head,int data){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}


int main(){
    node *head,*temp,*temp2;
    node *second;
    node *third;
    node *fourth;
    node *fifth;
    head=(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third=(node *)malloc(sizeof(node));
    fourth=(node *)malloc(sizeof(node));
    fifth=(node *)malloc(sizeof(node));
    head->data=5;
    head->next=second;
    second->data=15;
    second->next=third;
    third->data=25;
    third->next=fourth;
    fourth->data=35;
    fourth->next=fifth;
    fifth->data=90;
    fifth->next=NULL;
    printf("Before Insertion\n");
    travarsal(head);

    printf("//////////\n");
    printf("\nInsert At the end\n");
    head=insertAtEnd(head,99);
    travarsal(head);


    return 0;

}