#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -2147483648

int max(int a,int b){
    return a>b?a:b;
}

int maxCutVal(int *arr,int n){
    if(n<=0)
        return 0;
    int maxi=INT_MIN,i;
    for(i=0;i<n;i++){
        maxi=max(maxi,arr[i]+maxCutVal(arr,n-1-i));
    }
    return maxi;
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",maxCutVal(arr,N));
    free(arr);
    return 0;
}
