#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int max(int a,int b){
    return a>b?a:b;
}

int minDrops(int n,int k){
    if(k==1||k==0)
        return k;
    if(n==1)
        return k;
    int mini=INT_MAX,x;
    for(x=1;x<=k;x++){
        mini=min(mini,max(minDrops(n-1,x-1),minDrops(n,k-x)));
    }
    return mini+1;
}

int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    printf("%d",minDrops(N,K));
    return 0;
}
