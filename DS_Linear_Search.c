#include<stdio.h>
int Linear_search(int a[],int n,int x){
    int i;
    for (i=0;i<n;i++){
        if (a[i]==x){
            return i;
        }
    }
    i=-1;
    return i;
}
int main(){
    int arr[50]={10,20,30,40};
    int n=5;
    int x=30;
    int result=Linear_search(arr,n,x);
    printf("the number is in %d th position\n",result);
    return 0;
}