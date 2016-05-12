#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int editDist(char* str1,char* str2,int m,int n,int ins,int del,int rep){
    int dp[m+1][n+1],i,j,res;
    for(j=0;j<=n;j++)
        dp[0][j]=j*ins;
    for(i=1;i<=m;i++){
        dp[i][0]=i*del;
        for(j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                res=dp[i-1][j-1];
            else
                res=dp[i-1][j-1]+rep;
            dp[i][j]=min3(dp[i][j-1]+ins,dp[i-1][j]+del,res);
        }
    }
    return dp[m][n];
}

int main(){
    char s1[1002],s2[1002];
    int ins,del,rep;
    scanf("%s%s",s1,s2);
    scanf("%d%d%d",&ins,&del,&rep);
    printf("%d",editDist(s1,s2,strlen(s1),strlen(s2),ins,del,rep));
    return 0;
}

