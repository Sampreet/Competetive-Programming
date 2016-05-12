#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0

bool isSubsetSum(int *set,int n,int sum){
    bool subset[sum+1][n+1];
    int i,j;
    for(j=0;j<=n;j++)
        subset[0][j]=true;
    for(i=0;i<=sum;i++)
        subset[i][0]=false;
    for(i=1;i<=sum;i++){
        for(j=1;j<=n;j++){
            subset[i][j]=subset[i][j-1];
            if(i>=set[j-1])
                subset[i][j]=subset[i][j] || subset[i-set[j-1]][j-1];
        }
    }
    return subset[sum][n];
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
