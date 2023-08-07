#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define capacity 100

int queue[capacity];
unsigned int size=0;
unsigned int rear=capacity-1;
unsigned int front=0;

int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();

int main(){
    int ch,data;
    while(1){
        printf("--------------------------------------------\n");
        printf("Queue Array Implementation program\n");
        printf("-------------------------------------------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.size\n");
        printf("4.Get rare\n");
        printf("5.Get front\n");
        printf("6.Exit\n");
        printf("--------------------------------------------------\n");
        printf("Select an option\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the data to enqueue\n");
            scanf("%d",&data);
            if (enqueue(data))
            printf("Element is added to the queue.");
            else ("Queue is full\n");
            break;

        }
    }
}
int isFull(){
    return (size==capacity);
}
int isEmpty(){
    return (size==0);
}

int enqueue(int data){
    if (isFull()){
        return 0;
    }
}
