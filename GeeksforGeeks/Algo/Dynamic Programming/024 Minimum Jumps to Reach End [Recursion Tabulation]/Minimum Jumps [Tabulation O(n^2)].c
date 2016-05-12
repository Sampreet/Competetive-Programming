#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int minJumps(int *arr,int n){
    int jumps[n],i,j;
    if(n==0||arr[0]==0)
        return INT_MAX;
    jumps[0]=0;
    for(i=1;i<n;i++){
        jumps[i]=INT_MAX;
        for(j=0;j<i;j++){
            if(i<=j+arr[j] && jumps[j]!=INT_MAX){
                jumps[i]=min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
    return jumps[n-1];
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",minJumps(arr,N));
    free(arr);
    return 0;
}
