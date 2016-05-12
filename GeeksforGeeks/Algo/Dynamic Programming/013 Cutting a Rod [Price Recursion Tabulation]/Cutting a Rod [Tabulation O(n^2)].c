#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -2147483648

int max(int a,int b){
    return a>b?a:b;
}

int maxCutVal(int *arr,int n){
    int dp[n+1],i,j,maxi;
    dp[0]=0;
    for(i=1;i<=n;i++){
        maxi=INT_MIN;
        for(j=0;j<i;j++)
            maxi=max(maxi,arr[j]+maxCutVal(arr,i-1-j));
        dp[i]=maxi;
    }
    return dp[n];
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",maxCutVal(arr,N));
    free(arr);
    return 0;
}
