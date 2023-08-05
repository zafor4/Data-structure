#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head;
void createList(int n){
    node *newnode,*temp;
    int data,i;
    head=(node *)malloc(sizeof(node));
    if (head==NULL){
        printf("Unable to allocate memory\n");
        exit(0);
    }
    printf("Enter data for your first node : ");
    scanf("%d",&data);
    head->data=data;
    head ->next=NULL;
    temp=head;
    for ( i=2;i<=n;i++){
        newnode=(node *)malloc(sizeof(node));
        if (newnode==NULL){
            printf("Unable to allocate memory\n");
            exit(0);
        }
        printf("Enter the data to your node %d : ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;

        temp->next=newnode;
        temp=temp->next;
    }
}
void treversal(){
    node *ptr;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    ptr=head;
    while(ptr!=NULL){
        printf("Data = %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
int number_of_list_to_Create;
printf("Enter the number of list you want to create: ");
scanf("%d",&number_of_list_to_Create);
createList(number_of_list_to_Create);
printf("Data in the list \n");
treversal();

    return 0;
}