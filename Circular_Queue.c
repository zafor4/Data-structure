#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rare=-1;
void enqueue(int x){
    if (front==-1&&rare==-1){
        front =rare=0;
        queue[rare]=x;
    }
    else if ((rare+1)%N==front){
        printf("Queue is full\n");
    }
    else {
        rare=(rare+1)%N;
        queue[rare]=x;
    }
}
void dequeue(){
    if (front==-1&&rare==-1){
        printf("Empty\n");
    }
    else if (front==rare){
        printf("%d\n",queue[front]);
        front=rare=-1;
    }
    else {
        printf("%d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    int i=front;
    if (front==-1 && rare==-1){
        printf("Empty");
    }
while (i!=rare){
    printf("%d\n",queue[i]);
    i=(i+1)%N;
}
printf("%d\n",queue[rare]);
}
int main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    enqueue(0);
    enqueue(10);
    display();


    return 0;
}