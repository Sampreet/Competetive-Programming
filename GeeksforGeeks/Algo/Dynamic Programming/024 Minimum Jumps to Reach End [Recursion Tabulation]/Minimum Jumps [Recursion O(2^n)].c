#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int minJumps(int *arr,int l,int h){
    if(h==l)
        return 0;
    if(arr[l]==0)
        return INT_MAX;
    int min=INT_MAX,i,jumps;
    for(i=l+1;i<=h && i<=l+arr[l];i++){
        jumps=minJumps(arr,i,h);
        if(jumps!=INT_MAX && jumps+1<min)
            min=jumps+1;
    }
    return min;
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",minJumps(arr,0,N-1));
    free(arr);
    return 0;
}
