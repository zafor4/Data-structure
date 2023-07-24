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
node *insertAtFirst(node *head,int data){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=head;
  
    return ptr;

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
node *insertAfterANode(node *head,node *previousNode,int data){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=previousNode->next;  
    previousNode->next=ptr;
    return head;
}
node * insertINBetween(node *head,int data,int index){
    node *ptr=(node *)malloc(sizeof(node));
    node *p=head;
    int i=0;
    while (i!=index-1){
        p=p->next;
        i++;
    }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        return head;
    
}

int main(){
    node *head;
    node *second;
    node *third;
    node *fourth;
    head=(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third=(node *)malloc(sizeof(node));
    fourth=(node *)malloc(sizeof(node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=NULL;
    printf("Before Insertion\n");
    travarsal(head);

    head =insertAtFirst(head,0);
    printf("\nInsert at beginning\n");
    travarsal(head);
    printf("//////////\n");

    head=insertINBetween(head,56,1);
    printf("\nInsert in between\n");
    travarsal(head);
    printf("//////////\n");
    printf("\nInsert At the end\n");
    head=insertAtEnd(head,66);
    travarsal(head);
    printf("///////////\n");
    printf("\n Insert after a node \n");
    head=insertAfterANode(head,second,77);
    travarsal(head);


    return 0;

}