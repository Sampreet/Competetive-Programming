#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    return a<b?a:b;
}

int binomialCoeff(int n,int k){
    int C[k+1],i,j;
    C[0]=1;
    for(i=1;i<=n;i++){
        C[i]=0;
        for(j=min(i,k);j>0;j--){
            C[j]=C[j-1]+C[j];
        }
    }
    return C[k];
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d",binomialCoeff(n,k));
    return 0;
}
