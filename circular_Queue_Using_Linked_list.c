#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;
node *front=0;
node *rear=0;
void enqueue(int data){
    node *newnode;

    newnode=(node *)malloc(sizeof(node));
        newnode->data=data;
    newnode->next=0;

    if (front==0 && rear==0){
        front=rear=newnode;
        rear->next=front;
    }
        rear->next=newnode;
        rear=newnode;
        newnode->next=front;
}
void dequeue(){
    node *temp=front;
    if (front==0 && rear==0){
        printf("Empty\n");
    }
    else if (front==rear){
        front=rear=0;
    }
    else {
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek(){
    if (front==0 && rear==0){
        printf("Empty\n");
    }
    else {
        printf("%d\n",front->data);
    }
}
void display(){
    node *temp;
    temp=front;
        if (front==0 && rear==0){
        printf("Empty\n");
    }
    while (temp->next!=front){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
int main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    display();
    dequeue();
    peek();

    return 0;
}