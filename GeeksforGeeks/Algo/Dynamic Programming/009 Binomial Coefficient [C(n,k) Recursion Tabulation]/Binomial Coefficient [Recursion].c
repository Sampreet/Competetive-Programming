#include<stdio.h>

int binomialCoeff(int n,int k){
    if(k==0 || k==n)
        return 1;
    else
        return binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k);
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d",binomialCoeff(n,k));
    return 0;
}
