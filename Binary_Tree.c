#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *createNode(){
    int data;
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data (-1 for no node)\n");
    scanf("%d",&data);
    if (data==-1){
        return 0;
    }
    newnode->data=data;
    printf("Enter left child of %d\n",data);
    newnode->left=createNode();
    printf("Enter right child of %d\n",data);
    newnode->right=createNode();
    return newnode;

}
//preorder treversal.
void preorder(node *root){
    if (root==0){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);

}
void interorder(node *root){
        if (root==0){
        return;
    }
    
    interorder(root->left);
    printf("%d\t",root->data);
    interorder(root->right);
}
void postorder(node *root){
        if (root==0){
        return;
    }
    
    postorder(root->left);
    
    postorder(root->right);
    printf("%d\t",root->data);
}
int main(){
    node *root;
    root=0;
    root=createNode();
printf("Traversed preorder\n");
    preorder(root);
    printf("\nTreversed interorder\n");
    interorder(root);
    printf("\nTreversed postorder\n");
    postorder(root);


    return 0;
}