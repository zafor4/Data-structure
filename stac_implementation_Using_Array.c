#include <stdio.h>

#define N 5

int stack[N];
int top=-1;
void push(){
    int x;
    printf("Enter the data : ");
    scanf("%d",&x);
    if (top==N-1){
        printf("Overflow\n");
    }
    top++;
    stack[top]=x;
}
void pop(){
    int item;
    if (top==-1){
        printf("Underflow\n");
    }
    item=stack[top];
    top--;
    printf("the deleted item is = %d",item);
    
}
void peek(){
    if (top==-1){
        printf("Underflow\n");
    }
    else {
        printf("%d",stack[top]);
    }
}
void display(){
    int i;
    if (top==-1){
        printf("underflow\n");
        return;
    }
    for (i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}

int main() {
    return 0;
}
