#include<stdio.h>
#include<stdlib.h>

int countWays(int *S,int m,int n){
    int i,j,x,y;
    int dp[n+1][m];
    for(j=0;j<m;j++)
        dp[0][j]=1;
    for(i=1;i<=n;i++)
        for(j=0;j<m;j++){
            x=(i-S[j]>=0)?dp[i-S[j]][j]:0;
            y=(j>0)?dp[i][j-1]:0;
            dp[i][j]=x+y;
        }
    return dp[n][m-1];
}

int main(){
    int *S,M,N,i;
    scanf("%d%d",&M,&N);
    S=(int*)malloc(M*sizeof(int));
    for(i=0;i<M;i++){
        scanf("%d",&S[i]);
    }
    printf("%d",countWays(S,M,N));
    free(S);
    return 0;
}
