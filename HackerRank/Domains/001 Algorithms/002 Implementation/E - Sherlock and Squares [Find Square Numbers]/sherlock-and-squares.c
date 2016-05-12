#include<stdio.h>
#inlcude<math.h>
typedef int bool;
#define true 1
#define false 0
bool isPerfectSquare(long long x)
{
    long long s = sqrt(x);
    return (s*s == x);
}
int main()
{
    int t;
    long long a, b;
    scanf("%d",&t);
    while(t--))
    {
        scanf("%lld%lld",&a,&b);
        if(isPerfectSquare(a)){
            printf("%lld\n",(int)sqrt(b)-(int)sqrt(a)+1);
        }
        else {
            printf("%lld\n",(int)sqrt(b)-(int)sqrt(a));;
        }
    }
    return 0;
}
