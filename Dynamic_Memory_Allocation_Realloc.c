#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int *ptr;
    printf("Enter the value of Entity\n");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    printf("Enter the values\n");
    for (int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    printf("Enter the update entity amount\n");
    scanf("%d",&n);
    int *ptr1=(int *)realloc(ptr,n*sizeof(int));
    printf("previous adress %d\n new adress %d\n",ptr,ptr1);
    printf("Values are \n");
    for (int i=0;i<n;i++){
        printf("%d\t",*(ptr1+i));
    }
    free(ptr1);

    return 0;
}