#include<stdio.h>
void selection_sort(int a[],int n){
    int i,j,index_min,temp;
    for (i=0;i<n-1;i++){
        index_min=i;
        for (j=i+1;j<n;j++){
            if(a[j]<a[index_min]){
                index_min=j;
            }
        }
        if (index_min!=i){
            temp=a[i];
            a[i]=a[index_min];
            a[index_min]=temp;
        }
    }
    for (int k=0;k<n;k++){
        printf("%d\n",a[k]);
    }
}

void seelection_sort_practice(int a[],int n){
    int i,j,index_min,temp;
    for (i=0;i<n-1;i++){
        index_min=i;
        for (int j=i+1;j<n;j++){
            if (a[j]<a[index_min]){
                index_min=j;
            }
        }
            if (index_min!=i){
                temp=a[i];
                a[i]=a[index_min];
                a[index_min]=temp;
            }
        
    }
    for (i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}
int main(){
    int a[]={4,8,3,10,2};
    selection_sort(a,5);
    seelection_sort_practice(a,5);
    return 0;
}