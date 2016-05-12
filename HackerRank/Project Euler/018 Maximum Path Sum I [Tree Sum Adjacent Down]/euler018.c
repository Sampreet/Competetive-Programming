#include<stdio.h>

typedef struct{
    long long node;
    long long leftsum;
    long long rightsum;
}triangle;

int main(){
    int T,N,i,j;
    triangle tree[15][15];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            for(j=0;j<=i;j++){
                scanf("%lld",&tree[i][j].node);
                tree[i][j].leftsum=0;
                tree[i][j].rightsum=0;
            }
            for(j=i+1;j<N;j++){
                tree[i][j].node=0;
                tree[i][j].leftsum=0;
                tree[i][j].rightsum=0;
            }
        }
        for(i=N-2;i>=0;i--){
            for(j=0;j<=i;j++){
                tree[i][j].leftsum=tree[i+1][j].node;
                tree[i][j].rightsum=tree[i+1][j+1].node;
                if(tree[i][j].rightsum>tree[i][j].leftsum){
                    tree[i][j].node+=tree[i][j].rightsum;
                }
                else{
                    tree[i][j].node+=tree[i][j].leftsum;
                }
            }
        }
        printf("%lld\n",tree[0][0].node);
    }
    return 0;
}
