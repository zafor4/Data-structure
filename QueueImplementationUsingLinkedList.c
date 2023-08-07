#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;
node *front=0;
node *rear=0;
void enqueue(int x){
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=0;
    if (front==NULL&&rear==NULL){
        front=rear=newnode;
    }
    else {
        rear->next=newnode;
        rear=newnode;
    }
}
void display(){
    node *temp;
    if (front==NULL&&rear==NULL){
        printf("Empty");
    }
    else {
        temp=front;
        while(temp!=0){
            printf("%d\t",temp->data);
        
        temp=temp->next;
        }
    }
}
void dequeue(){
    node *temp;
    temp=front;
    if (front==NULL&& rear==NULL){
        printf("Empty");
    }
    else {
        
        printf("The data deleted is: %d\n",front->data);
        front=front->next;
        free(temp);

    }
}
int main(){
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    display();
    dequeue();
    display();


    return 0;
}