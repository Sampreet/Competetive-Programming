#include<stdio.h>
#include<stdlib.h>

int countWays(int *S,int m,int n){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(m<1 && n>0)
        return 0;
    return countWays(S,m-1,n) + countWays(S,m,n-S[m-1]);
}

int main(){
    int *S,M,N,i;
    scanf("%d%d",&M,&N);
    S=(int*)malloc(M*sizeof(int));
    for(i=0;i<M;i++){
        scanf("%d",&S[i]);
    }
    printf("%d",countWays(S,M,N));
    free(S);
    return 0;
}
