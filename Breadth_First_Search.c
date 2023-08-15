#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};
typedef struct Queue queue;
int isEmpty(queue *q){
    if (q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(queue *q,int val){
    if (isFull(q)){
        printf("Queue is full");
    }
    else {
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(queue *q){
    
}