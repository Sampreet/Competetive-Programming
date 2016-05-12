#include<stdio.h>

int main(){
    int A,N,K,i,*chamber;
    scanf("%d%d%d",&A,&N,&K);
    chamber=(int*)malloc(K*sizeof(int));
    N++;
    for(i=0;i<K;i++){
        chamber[i]=A%N;
        A/=N;
        printf("%d ",chamber[i]);
    }
    free(chamber);
    return 0;
}
