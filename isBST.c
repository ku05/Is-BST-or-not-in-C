#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(){
    struct node *newnode;
    int x;
    newnode=(struct node *) malloc (sizeof(struct node));
    printf("\n Enter the data (for no node create press -1) \n");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("\n Enter the left child of %d",x);
    newnode->left=create();
    printf("\n Enter the right child of %d",x);
    newnode->right=create();
    return newnode;
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int isBST(struct node *root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev !=NULL && root->data <=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
void main(){
    struct node *root;
    root=0;
    root=create();
    printf("inorder is\n");
    inorder(root);
    printf("\n preorder is \n");
    preorder(root);
    printf("\n postorder is\n");
    postorder(root);
    printf(" \n if(1) is bst otherwise no bst : %d",isBST(root));
}