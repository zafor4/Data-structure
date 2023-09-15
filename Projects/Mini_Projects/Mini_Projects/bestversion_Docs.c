#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char name[100];
    double salary;
    struct Node *next;
};
typedef struct Node node;
node *trash;
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

node *defaultdatabase(node *head){
    head=createlist("Alex Buisin",5000.00,NULL);
    node *temp = head;
    temp->next = createlist("Johnsen hyu",8000.50,NULL);
    temp = temp->next;
    temp->next = createlist("Huge kartes",4000.89,NULL);
    return head;
}

node *insert_At_Begining(node *head){
    char name[100];
    double salary;
    printf("Insert name:\n");
    scanf("%s",name);
    printf("Insert salary\n");
    scanf("%lf",&salary);
    node *temp;
    temp=head;
    head=createlist(name,salary,temp);
    return head;
}
node *insert_at_end(node *head){
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
    return head;
}

node *insert_at_User_choice(node *head) {
    int index_no;
    printf("Enter the number of index to insert a data: ");
    scanf("%d", &index_no);

    if (index_no < 1) {
        printf("Invalid index number.\n");
        return head;
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
            return head;
        }
        q = p;
        p = p->next;
    }

    if (q == NULL) {

        head = createlist(name, salary, p);
    } else {
        q->next = createlist(name, salary, p);
    }
    return head;
}


node * update_Database(node *head){
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

node * delete_From_First(node *head){
    node *temp=head;
    head=head->next;
    trash=temp;
    return head;
}
node * delete_From_last(node *head){
    node *temp=head;
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    trash=temp->next;
    temp->next=NULL;
    return head;
}

node * delete_On_User_Choice(node *head){
    node *temp=head;
    int index;
    printf("Enter the number of index to delete data : ");
    scanf("%d",&index);
    indx=index;
    if (index==1){
        delete_From_First(temp);
    }
    for (int i=2;i<index;i++){
        if (temp->next!=NULL){
            temp=temp->next;
        }
    }
    trash=temp->next;
    temp->next=temp->next->next;
    return head;
}

node *customdatabase(node *head){
    char name[100];
    double salary;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter salary: ");
    scanf("%lf", &salary);

    node *newNode = createlist(name, salary, NULL);
    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int selection;
    while (1){
        printf("Choose 1 to continue or 0 to exit\n");
        scanf("%d", &selection);
        if (selection == 0){
            break;  // Exit the loop
        }
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter salary: ");
        scanf("%lf", &salary);

        newNode = createlist(name, salary, NULL);
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}


node *delete_Undo(node *head){
    node *temp;
    int option;
    int undoselect;
    printf("Choose an option to delete a data\n");
    printf(" Enter 1 or 2 or 3 for begining ending custom\n");
    scanf("%d",&option);
    if (option==1){
        head=delete_From_First(head);
        printf("Data succesfully removed|n");
        displayList(head);
        printf("Undo?? \n click 1 for undo\n0 to terminate : ");
        scanf("%d",&undoselect);
        if (undoselect==1){
            temp=head;
            head=trash;
            trash->next=temp;
        }
    }
    else if (option==2){
        head=delete_From_last(head);
        printf("Data succesfully removed|n");
        displayList(head);
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
        head=delete_On_User_Choice(head);
        printf("Data succesfully removed|n");
        displayList(head);
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
    return head;
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

node *head1=NULL,*head2=NULL,*head3=NULL;
head1=defaultdatabase(head1);
// displayList(head1);
// head1=delete_Undo(head1);
// displayList(head1);
// head2=customdatabase(head2);
// displayList(head2);
while (1){
    int menu_Option;
    printf("Select an option : \n");
    printf("1--Create new database\n");
    printf("2--Your databases\n");
    // printf("2--update existing database\n");
    // printf("3--Delete an existing data from your database\n");
    // printf("4--Display existing dataset\n");
    printf("0--Exit\n");
    scanf("%d",&menu_Option);
    if (menu_Option==0){
        exit(0);
    }
    else if (menu_Option==1){
        head2=customdatabase(head2);
    }
    else if (menu_Option==2){
        printf("Your datasates:\n");
        printf("Datasate 1\nDataset 2\nDaraset 3\n");
        printf("Enter 1 or 2 or 3 to access the dataset 1 or 2 or 3\n");
        int choicein;
        scanf("%d",&choicein);
        if (choicein==1){
            printf("Dataset 1 :\n");
            displayList(head1);
            printf("ENter 1 to insert data:\n");
            printf("Enter 2 to delete\n");
            printf("Enter 3 to update\n");
            int choice3;
            scanf("%d",&choice3);
            if (choice3==1){
                printf("Enter the index of data to be inserted:\n Enter 1 to insert first\nenter 2 to ensert last\nenter 3 for custom\n");
                int choice4;
                scanf("%d",&choice4);
                if (choice4==1){
                    head1=insert_At_Begining(head1);
                    displayList(head1);
                }
                else if (choice4==2){
                    head1=insert_at_end(head1);
                    displayList(head1);
                }
                else {
                    head1=insert_at_User_choice(head1);
                    displayList(head1);
                }
            }
            else if (choice3==3){
            head1=update_Database(head1);
            displayList(head1);
        }
            else if (choice3==2){
                head1=delete_Undo(head1);
                displayList(head1);
            }
        }
        else if (choicein==2){
            printf("Dataset 1 :\n");
            displayList(head2);
            printf("ENter 1 to insert data:\n");
            printf("Enter 2 to delete\n");
            printf("Enter 3 to update\n");
            int choice3;
            scanf("%d",&choice3);
            if (choice3==1){
                printf("Enter the index of data to be inserted:\n Enter 1 to insert first\nenter 2 to ensert last\nenter 3 for custom\n");
                int choice4;
                scanf("%d",&choice4);
                if (choice4==1){
                    head2=insert_At_Begining(head2);
                    displayList(head1);
                }
                else if (choice4==2){
                    head2=insert_at_end(head2);
                    displayList(head2);
                }
                else {
                    head2=insert_at_User_choice(head2);
                    displayList(head2);
                }
            }
            else if (choice3==3){
            head2=update_Database(head2);
            displayList(head2);
        }
            else if (choice3==2){
                head2=delete_Undo(head2);
                displayList(head2);
            }
        }
    }
}
    return 0;
}