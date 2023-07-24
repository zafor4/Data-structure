#include<stdio.h>
#include<stdlib.h>
 struct Node {
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

node *DeleteTheFirstNode(node *head){
    node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
node * DeleteINBetween(node *head,int index){
    node *p=head;
    node *q=head->next;
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
        return head;
    
}
node *deleteAtEnd(node *head){
    node *p=head;
    node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    return head;
}
node *DeleteWithAGivenValue(node *head,int value){
    node *p=head;
    node *q=head->next;
    while (q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if (q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}
int main(){
    node *head;
    node *second;
    node *third;
    node *fourth;
    node *fifth;
    node *sixth;
    node *seventh;
    node *eightth;
    head=(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third=(node *)malloc(sizeof(node));
    fourth=(node *)malloc(sizeof(node));
    fifth=(node *)malloc(sizeof(node));
    sixth=(node *)malloc(sizeof(node));
    seventh=(node *)malloc(sizeof(node));
    eightth=(node *)malloc(sizeof(node));
    head->data=5;
    head->next=second;
    second->data=6;
    second->next=third;
    third->data=7;
    third->next=fourth;
    fourth->data=8;
    fourth->next=fifth;
    fifth->data=9;
    fifth->next=sixth;
    sixth->data=10;
    sixth->next=seventh;
    seventh->data=11;
    seventh->next=eightth;
    eightth->data=12;
    eightth->next=NULL;
    printf("Before deletion\n");
    travarsal(head);
    printf("///////////\n");


head=DeleteTheFirstNode(head);
printf("\nAfter deleting the first node\n");
travarsal(head);
    printf("///////////\n");
    head=DeleteINBetween(head,2);
    printf("\nAfter deleting node in between\n");
    travarsal(head);
    printf("///////////\n");
    head=deleteAtEnd(head);
    printf("\nAfter deleting at the end\n");
    travarsal(head);
        printf("///////////\n");
        head=DeleteWithAGivenValue(head,10);
        printf("\nafter deleting the given value\n");
        travarsal(head);


    return 0;
}