#include<stdio.h>
#define N 5
int queue[N];
int front =-1;
int rear=-1;
void enqueue(int x){
    if (rear==N-1){
        printf("Overflow\n");
    }
    else if (front==-1 && rear==-1){
        front =rear=0;
        queue[rear]=x;
    }
    else {
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if (front==-1&&rear==-1){
        printf("Underflow condition\n");
    }
    else if (front==rear){
        front=rear=-1;
    }
    else {
        printf("\nThe dequeued element is %d\n",queue[front]);
        front++;
    }
}
void display(){
    if (front==-1&&rear==-1){
        printf("\nQueue is empty\n");
    }
    else {
        for (int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}
void peak(){
    if (front==-1&&rear==-1){
        printf("Empty\n");
    }
    else {
        printf("%d",queue[front]);
    }
}
int main(){
    
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    printf("\nValues is queue\n");
    display();
    printf("\nPeak value\n");
    peak();
    dequeue();
    printf("\npeak after dequeing\n");
    peak();
    printf("\nvalues after dequeing\n");
    display();
}