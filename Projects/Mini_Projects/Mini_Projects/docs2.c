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
node* createLinkedListFromUserInput() {
    node *headu = NULL;
    node *tempu = NULL;
    int choice;

    printf("Press 1 to start\n");
    scanf("%d", &choice);

    while (choice) {
        node *newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return headu;
        }

        printf("Enter name:\n");
        scanf("%s", newnode->name);

        printf("Enter salary:\n");
        scanf("%lf", &(newnode->salary));

        newnode->next = NULL;

        if (headu == NULL) {
            headu = tempu = newnode;
        } else {
            tempu->next = newnode;
            tempu = newnode;
        }

        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
    }

    return headu;
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
        displayListFromFirst();
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
        displayListFromFirst();
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
        displayListFromFirst();
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

void displayListFromFirst()
{
     node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %s\nsalary = %lf $\n", n, temp->name,temp->salary);

            n++;

            temp = temp->next;
        }
    }
}
void displayList(node *takehead) {
    node *temp;
    int n = 1;

    if (takehead == NULL) {
        printf("List is empty.\n");
    } else {
        temp = takehead;
        printf("\nDATA IN THE LIST:\n");

        while (temp != NULL) {
            printf("DATA of %d node = %s\nsalary = %lf $\n", n, temp->name, temp->salary);

            n++;

            temp = temp->next;
        }
    }
}



int main(){
while (1){
    int menu_Option;
    printf("Select an option : \n");
    printf("1--Create new database\n");
    printf("2--update existing database\n");
    printf("3--Delete an existing data from your database\n");
    printf("4--Display existing dataset\n");
    printf("0--Exit\n");
    scanf("%d",&menu_Option);
    if (menu_Option==0){
        exit(0);
    }
    else if (menu_Option==1){
        node *head2 = createLinkedListFromUserInput();
        printf("Your new dataset:\n");
        displayList(head2);

    }
    else if (menu_Option==2){
        int choosed;
        printf("Choose an option to be updated:\n");
        printf("enter 1 for first dataset\n");
        printf("Enter 2 for second dataset\n");
        scanf("%d",&choosed);
        if (choosed==2){
            printf("Existing dataset\n");
            defaultdatabase();
            displayListFromFirst();
            update_Database();
            printf("After update\n");
            displayList(head);

        }
        else {
        ("Choose a valid option\n");
        }
    }
    else if (menu_Option==3){
                int choosed;
        printf("Choose an option to be updated:\n");
        printf("enter 1 for first dataset\n");
        printf("Enter 2 for second dataset\n");
        scanf("%d",&choosed);
        if (choosed==2){
            printf("Existing dataset\n");
            defaultdatabase();
            displayListFromFirst();
            delete_Undo();
            printf("Dataset after undo\n");
            displayListFromFirst();

        }
        else ("Choose a valid option");
    }
    else if (menu_Option==4){
        displayListFromFirst();
    }
}
    return 0;
}