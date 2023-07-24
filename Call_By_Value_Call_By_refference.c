#include<stdio.h>
void call_by_Value(int x,int y){
    x=20;
    y=10;
}
void call_by_refference(int* x, int* y){
    *x=20;
    *y=10;
}
int main(){
    int x=10,y=20;
    call_by_Value(x,y);
    printf("%d\t%d\n",x,y);
    call_by_refference(&x,&y);
    printf("%d\t%d\n",x,y);

    return 0;
}