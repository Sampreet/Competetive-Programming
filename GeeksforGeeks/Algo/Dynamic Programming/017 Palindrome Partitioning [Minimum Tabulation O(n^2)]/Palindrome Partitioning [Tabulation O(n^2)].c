#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int bool;
#define true 1
#define false 0
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int minPalinPart(char *str,int n){
    int C[n],i,j,k,L;
    bool P[n][n];
    for(i=0;i<n;i++){
        P[i][i]=true;
    }
    for(L=2;L<=n;L++){
        for(i=0;i<n-L+1;i++){
            j=i+L-1;
            if(L==2){
                P[i][j]=(str[i]==str[j]);
            }
            else
                P[i][j]=(str[i]==str[j]) && P[i+1][j-1];
        }
    }
    for(i=0;i<n;i++){
        if(P[0][i]==true)
            C[i]=0;
        else{
            C[i]=INT_MAX;
            for(j=0;j<i;j++)
                if(P[j+1][i]==true)
                    C[i]=min(C[i],1+C[j]);
        }
    }
    return C[n-1];
}

int main(){
   int N;
   char str[10002];
   scanf("%s",str);
   printf("%d",minPalinPart(str,strlen(str)));
   return 0;
}
