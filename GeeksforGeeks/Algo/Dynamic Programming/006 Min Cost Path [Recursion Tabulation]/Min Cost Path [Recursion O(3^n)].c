#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int minCost(int **cost,int m,int n){
    if(m<0 || n<0)
        return INT_MAX;
    else if(m==0 && n==0)
        return cost[m][n];
    else
        return cost[m][n]+min3(minCost(cost,m,n-1),minCost(cost,m-1,n),minCost(cost,m-1,n-1));

}

int main(){
    int **cost,M,N,i,j;
    scanf("%d%d",&M,&N);
    cost=(int**)malloc(M*sizeof(int*));
    for(i=0;i<M;i++){
        cost[i]=(int*)malloc(N*sizeof(int));
        for(j=0;j<N;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("%d",minCost(cost,M-1,N-1));
    free(cost);
    return 0;
}

