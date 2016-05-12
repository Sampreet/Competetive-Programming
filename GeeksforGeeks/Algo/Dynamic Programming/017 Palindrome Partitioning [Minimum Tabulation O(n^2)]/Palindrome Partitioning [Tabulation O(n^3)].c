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
    int C[n][n],i,j,k,L;
    bool P[n][n];
    for(i=0;i<n;i++){
        P[i][i]=true;
        C[i][i]=0;
    }
    for(L=2;L<=n;L++){
        for(i=0;i<n-L+1;i++){
            j=i+L-1;
            if(L==2){
                P[i][j]=(str[i]==str[j]);
            }
            else
                P[i][j]=(str[i]==str[j]) && P[i+1][j-1];
            if(P[i][j]==true)
                C[i][j]=0;
            else{
                C[i][j]=INT_MAX;
                for(k=i;k<=j-1;k++)
                    C[i][j]=min(C[i][j],C[i][k]+C[k+1][j]+1);
            }
        }
    }
    return C[0][n-1];
}

int main(){
   int N;
   char str[10002];
   scanf("%s",str);
   printf("%d",minPalinPart(str,strlen(str)));
   return 0;
}
