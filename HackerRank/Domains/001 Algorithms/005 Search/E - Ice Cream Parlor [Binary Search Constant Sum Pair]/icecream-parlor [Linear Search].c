#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,N,t,K,*arr,mark;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&K,&N);
        arr=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        mark=0;
        for(i=0;i<N;i++){
            if(arr[i]<K){
                arr[i]=K-arr[i];
                for(j=i+1;j<N;j++)
                    if(arr[i]==arr[j]){
                        printf("%d %d\n",i+1,j+1);
                        mark=1;
                        break;
                    }
            }
            if(mark==1){
                break;
            }
        }
        free(arr);
    }
    return 0;
}
