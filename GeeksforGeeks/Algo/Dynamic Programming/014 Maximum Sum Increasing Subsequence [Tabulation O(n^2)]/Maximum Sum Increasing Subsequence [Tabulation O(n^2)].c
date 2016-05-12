#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -2147483648

int max(int a,int b){
    return a>b?a:b;
}

int maxIncSum(int *arr,int n){
    int *msis,i,j,maxi;
    msis=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        msis[i]=arr[i];
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(arr[j]<arr[i] && msis[i]<msis[j]+arr[i])
                msis[i]=msis[j]+arr[i];
    maxi=INT_MIN;
    for(i=0;i<n;i++)
        maxi=max(maxi,msis[i]);
    free(msis);
    return maxi;
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",maxIncSum(arr,N));
    free(arr);
    return 0;
}
