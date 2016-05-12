#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
    return a>b?a:b;
}

int longPalinSubSeq(char *str){
    int n=strlen(str),i,j,cl,dp[n][n];
    for(i=0;i<n;i++)
        dp[i][i]=1;
    for(cl=2;cl<=n;cl++){
        for(i=0;i<n-cl+1;i++){
            j=i+cl-1;
            if(str[i]==str[j] && cl==2)
               dp[i][j]=2;
            else if(str[i]==str[j])
               dp[i][j]=dp[i+1][j-1]+2;
            else
               dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}

int main(){
    char str[1002];
    scanf("%s",str);
    printf("%d",longPalinSubSeq(str));
    return 0;
}
