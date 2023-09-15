#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char name[100];
    double salary;
    struct Node *next;
};
typedef struct Node node;
node *head=NULL;
node *trash=NULL;
node *head2=NULL;
int indx;



node* createlist( const char name[], double salary,node *next) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        return NULL;
    }
    strcpy(newnode->name, name);
    newnode->salary = salary;
    newnode->next = next;

    return newnode;
}

void defaultdatabase(){
    head=createlist("Alex Buisin",5000.00,NULL);
    node *temp = head;
    temp->next = createlist("Johnsen hyu",8000.50,NULL);
    temp = temp->next;
    temp->next = createlist("Huge kartes",4000.89,NULL);
}

void insert_At_Begining(){
    char name[100];
    double salary;
    printf("Insert name:\n");
    scanf("%s",name);
    printf("Insert salary\n");
    scanf("%lf",&salary);
    node *temp;
    temp=head;
    head=createlist(name,salary,temp);
}
void insert_at_end(){
    char name[100];
    double salary;
    printf("Insert name:\n");
    scanf("%s",name);
    printf("Insert salary\n");
    scanf("%lf",&salary);
    node *temp;
    temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=createlist(name,salary,NULL);
}

void insert_at_User_choice() {
    int index_no;
    printf("Enter the number of index to insert a data: ");
    scanf("%d", &index_no);

    if (index_no < 1) {
        printf("Invalid index number.\n");
        return;
    }

    char name[100];
    double salary;

    printf("Insert name:\n");
    scanf("%s", name);

    printf("Insert salary:\n");
    scanf("%lf", &salary);

    node *p = head;
    node *q = NULL;

    for (int i = 1; i < index_no; i++) {
        if (p == NULL) {
            printf("Invalid index number.\n");
            return;
        }
        q = p;
        p = p->next;
    }

    if (q == NULL) {

        head = createlist(name, salary, p);
    } else {
        q->next = createlist(name, salary, p);
    }
}


void update_Database(){
    int index;
    char name[100];
    double salary;
    printf("Enter the index of data you want to update : ");
    scanf("%d",&index);
    node *temp=head;
    for (int i=1;i<index;i++){
        temp=temp->next;
    }
    printf("provide new data : \n");
    printf("Enter name: ");
    scanf("%s",name);
    printf("\nEnter new salary : ");
    scanf("%lf",&salary);

    strcpy(temp->name, name);
    temp->salary=salary;

}
void update_Database_V2(node *mainhead) {
    int index;
    char name[100];
    double salary;
    printf("Enter the index of data you want to update : ");
    scanf("%d", &index);

    if (index < 1) {
        printf("Invalid index number.\n");
        return;
    }

    node *temp = mainhead;
    for (int i = 1; i < index; i++) {
        if (temp == NULL) {
            printf("Invalid index number.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Provide new data : \n");
    printf("Enter name: ");
    scanf("%s", name);
    printf("\nEnter new salary : ");
    scanf("%lf", &salary);

    // Dynamically allocate memory for the name field to avoid overflow
    char *newName = (char *)malloc(strlen(name) + 1);
    if (newName == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newName, name);

    // Update the node with new data
    strcpy(temp->name, newName);
    temp->salary = salary;

    // Free the dynamically allocated memory
    free(newName);
}


void delete_From_First(){
    node *temp=head;
    head=head->next;
    trash=temp;
}
void delete_From_last(){
    node *temp=head;
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    trash=temp->next;
    temp->next=NULL;
}

void delete_On_User_Choice(){
    node *temp=head;
    int index;
    printf("Enter the number of index to delete data : ");
    scanf("%d",&index);
    indx=index;
    if (index==1){
        delete_From_First();
    }
    for (int i=2;i<index;i++){
        if (temp->next!=NULL){
            temp=temp->next;
        }
    }
    trash=temp->next;
    temp->next=temp->next->next;
}
void delete_Undo(){
    node *temp;
    int option;
    int undoselect;
    printf("Choose an option to delete a data\n");
    printf(" Enter 1 or 2 or 3 for begining ending custom\n");
    scanf("%d",&option);
    if (option==1){
        delete_From_First();
        printf("Data succesfully removed|n");
        displayListFromFirst(head);
        printf("Undo?? \n click 1 for undo\n0 to terminate : ");
        scanf("%d",&undoselect);
        if (undoselect==1){
            temp=head;
            head=trash;
            trash->next=temp;
        }
    }
    else if (option==2){
        delete_From_last();
        printf("Data succesfully removed|n");
        displayListFromFirst(head);
        printf("Undo?? \n click 1 for undo\n0 to terminate : ");
        scanf("%d",&undoselect);
        if (undoselect==1){
            temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=trash;
        }
    }
    else {
        delete_On_User_Choice();
        printf("Data succesfully removed|n");
        displayListFromFirst(head);
        printf("Undo?? \n click 1 for undo\n0 to terminate : ");
        scanf("%d",&undoselect);
        if (undoselect==1){
            node *p,*q;
            p=head;
            q=head->next;
            for (int i=2;i<indx;i++){
                p=p->next;
                q=q->next;
            }
            p->next=trash;
            trash->next=q;

        }
    }
}

void displayListFromFirst(node *takehead)
{
     node * temp;
    int n = 1;

    if(takehead == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = takehead;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %s\nsalary = %lf $\n", n, temp->name,temp->salary);

            n++;

            temp = temp->next;
        }
    }
}

int main(){
    // defaultdatabase();
    // // insert_At_Begining();
    // // insert_at_end();
    // // insert_at_User_choice();
    displayListFromFirst(head);

    // update_Database();
    // // // delete_From_First();
    // // // delete_From_last();
    // // // delete_On_User_Choice();
    // // delete_Undo();
    // displayListFromFirst(head);
    // // // printf("%lf",trash->salary);


while(1){
    int menu_Option;
    printf("Select an option : \n");
    printf("1--Create new database\n");
    printf("2--update existing database\n");
    printf("3--Delete an existing data from your database\n");
    printf("4--Display dataset\n");
    printf("0--Exit\n");
    scanf("%d",&menu_Option);
    if (menu_Option==0){
        exit(0);
    }
    else if (menu_Option==1){
         node *head2,*newnode2,*temp2;
        head2=0;
        int choice;
        printf("Press 1 to start\n");
        scanf("%d",&choice);
        while(choice){
        newnode2=(node *)malloc(sizeof(node));
        printf("Enter name\n");
        char name[100];
        scanf("%s",name);
        strcpy(newnode2->name, name);
        printf("Enter salary: ");
        scanf("%lf",&(newnode2->salary));
        newnode2->next=0;
        if (head2==0){
            head2=temp2=newnode2;
            temp2=newnode2;
        }
        else {
            temp2->next=newnode2;
            temp2=newnode2;
        }
        printf("Do you want to continue(0,1)\n");
        scanf("%d",&choice);
    }
    printf("Your new dataset :\n");
displayListFromFirst(head2);
    }
    else if (menu_Option == 2){
    printf("select dataset to update\n");
    printf("Enter 1 for the first dataset\n");
    printf("Enter 2 for the second dataset\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1){
        update_Database();
        displayListFromFirst(head);
    }
    else{
        exit(0);
    }
}

    

// }



    return 0;
}
