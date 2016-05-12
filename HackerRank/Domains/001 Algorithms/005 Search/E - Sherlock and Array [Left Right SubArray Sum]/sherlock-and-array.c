#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,k=0,t,*arr;
    long long sum2,*sum1,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
        sum1=(long long *)malloc((n)*sizeof(long long));
        arr=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
            sum1[i]=sum-arr[i];
        }
        k=0;
        for(i=0;i<n;i++){
            sum2=sum-sum1[n-1-i]-arr[n-1-i];
            if(sum2==sum1[n-i-1])
            {
                k=1;
                break;
            }
        }
        if(k==1)
            printf("YES\n");
        else
            printf("NO\n");
        free(arr);
    }
    return 0;
}
