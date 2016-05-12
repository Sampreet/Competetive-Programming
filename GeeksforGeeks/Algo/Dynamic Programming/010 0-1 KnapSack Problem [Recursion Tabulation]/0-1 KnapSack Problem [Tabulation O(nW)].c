#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

int knapSack(int W,int *wt,int *val,int n){
    int i,w,dp[n+1][W+1];
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0)
                dp[i][w]=0;
            else if(wt[i-1]<=w)
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main(){
    int W,N,*wt,*val,i;
    scanf("%d%d",&N,&W);
    wt=(int*)malloc(N*sizeof(int));
    val=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d%d",&val[i],&wt[i]);
    }
    printf("%d",knapSack(W,wt,val,N));
    return 0;
}
