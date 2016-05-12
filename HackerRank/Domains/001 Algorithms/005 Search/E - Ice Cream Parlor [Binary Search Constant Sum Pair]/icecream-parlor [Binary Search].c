#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

int binarySearch(int *arr,int low,int high,int x){
    if(high>=low){
        int mid=low+(high-low)/2;
        if(x==arr[mid])
            return mid;
        return max(binarySearch(arr,(mid+1),high,x),binarySearch(arr,low,(mid-1),x));
    }
    return -1;
}

int main(){
    int i,j,N,t,K,*arr;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&K,&N);
        arr=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        for(i=0;i<N;i++){
            if(arr[i]<K){
                j=binarySearch(arr,i+1,N-1,K-arr[i]);
                if(j!=-1){
                    printf("%d %d\n",i+1,j+1);
                    break;
                }
            }
        }
        free(arr);
    }
    return 0;
}
