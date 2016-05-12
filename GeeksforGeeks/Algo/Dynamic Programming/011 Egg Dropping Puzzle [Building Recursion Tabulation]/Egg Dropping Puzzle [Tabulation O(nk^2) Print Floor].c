#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int max(int a,int b){
    return a>b?a:b;
}

int minDrops(int n,int k){
    int dp[n+1][k+1],i,j,x;
    for(i=1;i<=n;i++){
        dp[i][1]=1;
        dp[i][0]=0;
    }
    for(j=1;j<=k;j++)
        dp[1][j]=j;
    for(i=2;i<=n;i++){
        for(j=2;j<=k;j++){
            dp[i][j]=INT_MAX;
            for(x=1;x<=j;x++){
                dp[i][j]= min(1+max(dp[i-1][x-1],dp[i][j-x]),dp[i][j]);
            }
        }
    }
    for(j=1;j<=k;j++){
        if(dp[n][j-1]!=dp[n][j])
            printf("%d\t",j);
    }
    return dp[n][k];
}

int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    printf("\n%d",minDrops(N,K));
    return 0;
}
