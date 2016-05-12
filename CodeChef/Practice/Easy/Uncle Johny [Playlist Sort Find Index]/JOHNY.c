#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,n,i,j,*arr,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        arr=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        scanf("%d",&k);
        k=arr[k-1];
        j=0;
        for(i=0;i<n;i++){
            if(arr[i]<k){
                j++;
            }
        }
        printf("%d\n",j+1);
        free(arr);
    }
    return 0;
}
