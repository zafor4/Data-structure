#include<stdio.h>
#include<stdlib.h>
struct Point
{
    int data;
    struct Point *pt;
};
typedef struct Point point;

int main(){
    
    point *head;
    head=(point*)malloc(sizeof(point));
    head->data=5;
    head->pt=(point*)malloc(sizeof(point));
    head->pt->data=7;
    head->pt->pt=(point*)malloc(sizeof(point));
    head->pt->pt->data=10;
    head->pt->pt->pt=NULL;
    printf("%d",(head->data));

    return 0;
}