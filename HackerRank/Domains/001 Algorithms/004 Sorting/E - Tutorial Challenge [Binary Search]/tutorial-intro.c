#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *arr,int low,int high,int x){
    if(high>=low){
        int mid=low+(high-low)/2;
        if(x==arr[mid])
            return mid;
        if(x>arr[mid])
            return binarySearch(arr,(mid+1),high,x);
        else
            return binarySearch(arr,low,(mid-1),x);
    }
    return -1;
}

int main(){
    int x,N,*arr,i;
    scanf("%d%d",&x,&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",binarySearch(arr,0,N-1,x));
    free(arr);
    return 0;
}
