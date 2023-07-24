#include<stdio.h>
int recoursion(int number){
    if (number==1||number==0){
        return 1;
    }
    else {
        return (number*recoursion(number-1));
    }
    }
int main(){
    printf("%d",recoursion(5));
    return 0;
}