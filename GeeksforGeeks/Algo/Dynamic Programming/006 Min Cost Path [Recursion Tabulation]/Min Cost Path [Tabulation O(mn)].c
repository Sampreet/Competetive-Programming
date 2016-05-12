#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int minCost(int **cost,int M,int N,int m,int n){
    int i,j,dp[M][N];
    dp[0][0]=cost[0][0];
    for(i=1;i<=m;i++)
        dp[i][0]=dp[i-1][0]+cost[i][0];
    for(j=1;j<=n;j++)
        dp[0][j]=dp[0][j-1]+cost[0][j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            dp[i][j]=cost[i][j]+min3(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
    return dp[m][n];
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
    printf("%d",minCost(cost,M,N,M-1,N-1));
    free(cost);
    return 0;
}

