#include<stdio.h>
# include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;
void travarsse(node *ptr){
    while (ptr!=NULL){
        printf("element = %d\n",ptr->data);
        ptr=ptr->next;
        
    }
}
int main(){
    node *head;
    node *second;
    node *third;
    head =(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third =(node *)malloc(sizeof(node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    travarsse(head);
    return 0;
}