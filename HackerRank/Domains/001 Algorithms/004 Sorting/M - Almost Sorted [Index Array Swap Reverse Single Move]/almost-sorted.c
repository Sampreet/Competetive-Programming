#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,N,*arr,sz=0,*index,left,right;
    scanf("%d",&N);
    index=(int*)malloc(sizeof(int));
    index[0]=0;
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
        if(i>0){
            if(arr[i]<arr[i-1]){
                if(sz<2||i-1-index[sz-1]==1){
                    sz++;
                    index=realloc(index,sz*sizeof(int));
                    index[sz-1]=i-1;
                }
                else{
                    printf("no\n");
                    free(arr);
                    return 0;
                }
            }
        }
    }
    if(sz==0){
        printf("yes\n");
        free(arr);
        return 0;
    }
    left=index[0];
    right=index[sz-1]+1;
    if((left==0||arr[right]>=arr[left-1]) && (right==N-1||arr[left]<=arr[right+1]))
        printf("yes\n%s %d %d\n",(sz<=2)?"swap":"reverse",left+1,right+1);
    else
        printf("no\n");
    free(arr);
    return 0;
}
