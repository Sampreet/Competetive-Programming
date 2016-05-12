#include<stdio.h>

int main()
{
    int n,a,sum=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        sum+=a;
    }
    printf("%d",sum);
    return 0;
}
