#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,*arr,k,count=0;
    scanf("%d%d",&n,&k);
    arr = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        for(j=0;j<i;j++)
        {
            if((arr[i]+arr[j])%k==0){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
