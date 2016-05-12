#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0

bool findPartition(int *arr,int n){
    int sum=0,i,j;
    for(i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2!=0)
        return false;
    bool part[sum/2+1][n+1];
    for(i=0;i<=n;i++)
        part[0][i] = true;
    for(i=1;i<=sum/2;i++)
        part[i][0]=false;
    for(i=1;i<=sum/2;i++){
        for(j=1;j<=n;j++){
            part[i][j]=part[i][j-1];
            if(i>=arr[j-1])
                part[i][j]=part[i][j] || part[i-arr[j-1]][j-1];
        }
    }
    /*
    for(i=0;i<=sum/2;i++){
        for(j=0;j<=n;j++)
            printf("%4d",part[i][j]);
        printf("\n");
    }*/

    return part[sum/2][n];
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
