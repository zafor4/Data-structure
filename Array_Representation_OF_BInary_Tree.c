#include<stdio.h>
void leftchild(int arr[],int n,int input){
    printf("%d\n",arr[(2*input)+1]);
    
}
void rightchild(int arr[],int n,int input){
    printf("%d\n",arr[(2*input)+2]);
    
}
void parent(int arr[],int n,int input){
    printf("%d\n",arr[(2*input)+1]);
    
}
int main(){
    int arr[]={10,3,25,8,7,2};
    int n=sizeof(arr)/sizeof(int);
    int input;
    scanf("%d",&input);
    leftchild(arr,n,input);
    return 0;
    
}