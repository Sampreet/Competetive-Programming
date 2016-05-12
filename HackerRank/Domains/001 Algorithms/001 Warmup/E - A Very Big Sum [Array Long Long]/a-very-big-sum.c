#include<stdio.h>

int main()
{
    long long n,a,sum=0;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld",&a);
        sum+=a;
    }
    printf("%lld",sum);
    return 0;
}
