#include<stdio.h>
void insertion_sort(int a[],int n){
    int i,j,item;
    for (i=1;i<n;i++){
        item=a[i];
        j=i-1;
        while (j>=0 && a[j]>item)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
        
    }
    for (i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

}
void insertion_sort_practice(int a[],int n){
    int i,j,item;
    for (i=1;i<n;i++){
        item=a[i];
        j=i-1;
    }
    while (j>=0&&a[j]>item){
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=item;
    for (i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int a[]={5,4,3,2,1};
    insertion_sort(a,5);
    printf("\n");
    insertion_sort_practice(a,5);
    return 0;
}