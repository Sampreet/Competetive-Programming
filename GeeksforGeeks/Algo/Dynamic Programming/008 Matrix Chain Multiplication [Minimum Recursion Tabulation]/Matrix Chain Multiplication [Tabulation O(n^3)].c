#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int minMatMult(int *arr,int n){
    int dp[n][n],i,j,k,L;
    for(i=1;i<n;i++)
        dp[i][i]=0;
    for(L=2;L<n;L++){
        for(i=1;i<=n-L+1;i++){
            j=i+L-1;
            dp[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[j]*arr[k]);
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",minMatMult(arr,N));
    free(arr);
    return 0;
}
