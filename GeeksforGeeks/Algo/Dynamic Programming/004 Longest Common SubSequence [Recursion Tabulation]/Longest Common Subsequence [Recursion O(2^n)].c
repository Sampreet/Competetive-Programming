#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

int longCommSubSeq(char *X,char *Y,int m,int n){
    if(n==0 || m==0)
        return 0;
    if(X[m-1]==Y[n-1]){
        return 1+longCommSubSeq(X,Y,m-1,n-1);
    }
    else{
        return max(longCommSubSeq(X,Y,m-1,n),longCommSubSeq(X,Y,m,n-1));
    }
}

int main(){
    char str1[1002],str2[1002],M,N;
    scanf("%s%s",str1,str2);
    M=strlen(str1);
    N=strlen(str2);
    printf("%d\n",longCommSubSeq(str1,str2,M,N));
    return 0;
}
