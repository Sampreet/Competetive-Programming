#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0

bool isSubsetSum(int *set,int n,int sum){
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;
    if(set[n-1]>sum)
        return isSubsetSum(set,n-1,sum);
    return isSubsetSum(set,n-1,sum) || isSubsetSum(set,n-1,sum-set[n-1]);
}

int main(){
    int i,N,sum,*arr;
    scanf("%d%d",&N,&sum);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    if(isSubsetSum(arr,N,sum)==true)
        printf("Found Subset.");
    else
        printf("No Subset found.");
    free(arr);
    return 0;
}
