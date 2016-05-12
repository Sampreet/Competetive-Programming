#include<stdio.h>

int main()
{
    int n,**a,sum1=0,sum2=0,i,j;
    scanf("%d",&n);
    a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(j==i)
                sum1+=a[i][j];
            if(j+i+1==n)
                sum2+=a[i][j];
        }
    }
    printf("%d",abs(sum1-sum2));
    free(a);
    return 0;
}
