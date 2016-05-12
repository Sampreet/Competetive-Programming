#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int min(int a,int b){
    return a<b?a:b;
}

int minMatMult(int *arr,int i,int j){
    if(i==j)
        return 0;
    int k,mini=INT_MAX;
    for(k=i;k<j;k++){
        mini=min(minMatMult(arr,i,k)+minMatMult(arr,k+1,j)+arr[i-1]*arr[k]*arr[j],mini);
    }
    return mini;
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",minMatMult(arr,1,N-1));
    free(arr);
    return 0;
}
