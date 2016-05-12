#include<stdio.h>
#include<stdlib.h>

int main() {

    int V,N,*arr,i,index;
    scanf("%d%d",&V,&N);
    arr=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
        if(arr[i]==V)
            index=i;
    }
    printf("%d\n",index);
    free(arr);
    return 0;
}
