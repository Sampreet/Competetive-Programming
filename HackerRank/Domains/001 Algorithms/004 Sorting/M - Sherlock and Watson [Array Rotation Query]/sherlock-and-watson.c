#include<stdio.h>
#include<stdlib.h>

int main(){
    int N,K,Q,q,*arr;
    scanf("%d%d%d",&N,&K,&Q);
    arr=(int*)malloc(N*sizeof(int));
    for(q=0;q<N;q++){
        scanf("%d",&arr[q]);
    }
    while(Q--){
        scanf("%d",&q);
        printf("%d\n",arr[((N-K%N)%N+q)%N]);
    }
    free(arr);
    return 0;
}
