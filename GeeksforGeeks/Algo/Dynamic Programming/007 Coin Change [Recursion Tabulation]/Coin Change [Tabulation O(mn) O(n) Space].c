#include<stdio.h>
#include<stdlib.h>

int countWays(int *S,int m,int n){
    int i,j;
    int dp[n+1];
    for(i=0;i<=n;i++)
        dp[i]=0;
    dp[0]=1;
    for(i=0;i<m;i++)
        for(j=S[i];j<=n;j++){
            dp[j]+=dp[j-S[i]];
        }
    return dp[n];
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
