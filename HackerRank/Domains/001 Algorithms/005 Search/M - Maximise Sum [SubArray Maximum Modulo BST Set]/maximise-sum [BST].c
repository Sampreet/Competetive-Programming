#include<stdio.h>
#include<stdlib.h>
#define LCHILD(x) 2*x+1
#define RCHILD(x) 2*x+2
#define PARENT(x) x/2

struct node{
    long long data;
    struct node *right,*left,*parent;
};

long long max(long long a,long long b){
    return a>b?a:b;
}

struct node* search(struct node* root,long long key)
{
    if(root==NULL||root->data==key)
       return root;
    if(root->data<key)
       return search(root->right,key);
    return search(root->left,key);
}

struct node* newNode(long long data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->parent=NULL;
    return(node);
}

struct node *minValue(struct node* node){
    struct node* current=node;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct node* insert(struct node* node,long long data){
    if(node==NULL)
        return(newNode(data));
    else{
        struct node *temp;
        if(data<=node->data){
             temp=insert(node->left,data);
             node->left=temp;
             temp->parent=node;
        }
        else{
            temp=insert(node->right,data);
            node->right=temp;
            temp->parent=node;
        }
        return node;
    }
}

struct node * inOrderSuccessor(struct node *root,struct node *n){
    if(n->right!=NULL)
        return minValue(n->right);
    struct node *p=n->parent;
    while(p!=NULL && n==p->right)
    {
        n=p;
        p=p->parent;
    }
    return p;
}

int main(){
    long long N,t,preSum,mod,x,i,maxi;
    struct node *root,*k;
    scanf("%lld",&t);
    while(t--){
        maxi=0;
        root=NULL;
        scanf("%lld%lld",&N,&mod);
        root=insert(root,0);
        preSum=0;
        for(i=1;i<=N;i++){
            scanf("%lld",&x);
            preSum=(preSum+x%mod)%mod;
            maxi=max(maxi,preSum);
            root=insert(root,preSum);
            k=search(root,preSum);
            k=inOrderSuccessor(root,k);
            if(k!=NULL)
                maxi=max(maxi,mod+preSum-k->data);
        }
        printf("%lld\n",maxi);
    }
    return 0;
}
