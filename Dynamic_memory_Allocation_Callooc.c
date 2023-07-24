#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int *ptr;
    printf("Enter the number of element to store\n");
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));
    printf("Enter the elements\n");
    for (int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    printf("The values are :\t");
    for (int i=0;i<n;i++){
        printf("%d\t",*(ptr+i));
    }
    free(ptr);

    return 0;
}