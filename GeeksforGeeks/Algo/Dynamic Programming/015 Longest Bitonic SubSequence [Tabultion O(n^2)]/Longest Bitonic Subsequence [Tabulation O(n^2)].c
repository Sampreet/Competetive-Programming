#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -2147483648

int max(int a,int b){
    return a>b?a:b;
}

int longBitonicSub(int *arr,int n){
    int *lis,*lds,i,j,maxi;
    lis=(int*)malloc(n*sizeof(int));
    lds=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        lis[i]=1;
        lds[i]=1;
    }
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(arr[j]<arr[i] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    maxi=INT_MIN;
    for(i=n-2;i>=0;i--)
        for(j=n-1;j>i;j--)
            if(arr[j]<arr[i] && lds[i]<lds[j]+1)
                lds[i]=lds[j]+1;
    maxi=lds[0]+lis[0]-1;
    for(i=1;i<n;i++)
        maxi=max(maxi,lis[i]+lds[i]-1);
    free(lis);
    free(lds);
    return maxi;
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",longBitonicSub(arr,N));
    free(arr);
    return 0;
}
