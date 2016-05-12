#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

int maxIndepSetSize(struct node *root){
    if(root==NULL)
        return 0;
    int size_excl=maxIndepSetSize(root->left)+maxIndepSetSize(root->right),size_incl=1;
    if(root->left){
        size_incl+=maxIndepSetSize(root->left->left)+maxIndepSetSize(root->left->right);
    }
    if(root->right){
        size_incl+=maxIndepSetSize(root->right->left)+maxIndepSetSize(root->right->right);
    }
    return max(size_incl,size_excl);
}

int main(){
    struct node *root=newNode(20);
    root->left=newNode(8);
    root->left->left=newNode(4);
    root->left->right=newNode(12);
    root->left->right->left=newNode(10);
    root->left->right->right=newNode(14);
    root->right=newNode(22);
    root->right->right=newNode(25);
    printf("%d",maxIndepSetSize(root));
    return 0;
}
