#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *previous;
    char name[100];
    struct Node *next;
};
typedef struct Node node;

node *createNode(node *head, int data, char name[]) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = data;
    strcpy(newNode->name, name);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
    } else {
        newNode->next = head;
        newNode->previous = head->previous;
        head->previous->next = newNode;
        head->previous = newNode;
    }

    return head;
}

void traversal(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *current = head;
    do {
        printf("%d %s\n", current->data, current->name);
        current = current->next;
    } while (current != head);
}

int main() {
    node *head = NULL;
    head = createNode(head, 10, "a");
    head = createNode(head, 20, "b");
    head = createNode(head, 30, "c");
    head = createNode(head, 40, "d");
    head = createNode(head, 50, "d");
    head = createNode(head, 60, "d");
    head = createNode(head, 70, "d");
    head = createNode(head, 80, "d");

    traversal(head);
    node *current = head;
    do {
        node *temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    return 0;
}
