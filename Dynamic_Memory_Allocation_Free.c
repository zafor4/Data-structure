#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,*ptr;
    printf("Enter the number of value to store \n");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int ));
    printf("Enter the values\n");
    for (int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    printf("The values before using the free function\n");
    for (int i=0;i<n;i++){
        printf("%d\t",*(ptr+i));
    }
    printf("\nThe memory location alocated before using the free function %d\n",ptr);
    free(ptr);
    printf("\nthe values after using the free function\n");
    for (int i=0;i<n;i++){
        printf("%d\t",*(ptr+i));
    }
    printf("\nThe memory location alocated after using the free function %d\n",ptr);

    return 0;
}