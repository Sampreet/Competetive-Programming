#include<stdio.h>

int hasSubsetSum(int *subset,int n,int sum)
{
   if(sum==0)
     return 1;
   if(n==0 && sum!=0)
     return 0;
   if (subset[n-1] > sum)
     return hasSubsetSum(subset, n-1, sum);
   return hasSubsetSum(subset, n-1, sum) || hasSubsetSum(subset, n-1, sum-subset[n-1]);
}

int main(){
    int t,i,N,M,in,*cash;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        cash=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            scanf("%d",&cash[i]);
        }
        if(hasSubsetSum(cash,N,M)){
            printf("Yes\n");
        }
        else
            printf("No\n");
        free(cash);
    }
    return 0;
}
