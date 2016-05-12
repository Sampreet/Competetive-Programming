#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0

bool isSubsetSum(int *arr,int n,int sum){
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;
    if(arr[n-1]>sum)
        return isSubsetSum(arr,n-1,sum);
    return isSubsetSum(arr,n-1,sum)||isSubsetSum(arr,n-1,sum-arr[n-1]);
}

bool findPartition(int *arr,int n){
    int sum=0,i;
    for(i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2==1)
        return false;
    return isSubsetSum(arr,n,sum/2);
}

int main(){
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    if(findPartition(arr,N)==true)
        printf("YES");
    else
        printf("NO");
    free(arr);
    return 0;
}
