#include <stdio.h>
#include <stdlib.h>

int main() {
    int t,N,*arr,i,j,temp;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        arr=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        for(i=1;i<N-1;i++){
            for(j=N-3;j>=i-1;j--){
                if(arr[j]!=i && arr[j+1]!=i && arr[j+2]!=i){
                    continue;
                }
                while(arr[j]!=i){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=arr[j+2];
                    arr[j+2]=temp;
                }
            }   
        }
        if(arr[N-1]==N-1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
        free(arr);
    }
    return 0;
}