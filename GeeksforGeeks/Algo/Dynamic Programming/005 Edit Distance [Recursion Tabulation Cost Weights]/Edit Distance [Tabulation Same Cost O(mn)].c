#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int editDist(char* str1,char* str2,int m,int n){
    int dp[m+1][n+1],i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j] = i;
            else if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min3(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main(){
    char s1[1002],s2[1002];
    scanf("%s%s",s1,s2);
    printf("%d",editDist(s1,s2,strlen(s1),strlen(s2)));
    return 0;
}

