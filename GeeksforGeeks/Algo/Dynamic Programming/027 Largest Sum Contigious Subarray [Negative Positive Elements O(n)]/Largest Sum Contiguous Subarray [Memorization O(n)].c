#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

int maxSumSubArray(int *arr,int n){
    int max_so_far=arr[0],i,curr_max=arr[0];
    for(i=1;i<n;i++){
        curr_max=max(arr[i],curr_max+arr[i]);
        max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far;
}

int main(){
    int *arr,N,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",maxSumSubArray(arr,N));
    free(arr);
    return 0;
}
