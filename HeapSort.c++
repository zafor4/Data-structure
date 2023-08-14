#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if (l<n &&arr[l]>arr[largest]){
        largest=l;
    }
    if (r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if (largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void printArray(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
int arr[]={1,2,3,4,5,6,7};
int n=sizeof(arr)/sizeof(int);
heapify(arr,n,0);
printArray(arr,n);

    return 0;
}