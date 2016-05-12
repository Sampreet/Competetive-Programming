#include<stdio.h>

//long long check(long long a, long long x, long long N, long long sum){
//    if(a*x >= N)
//    {
//        return sum;
//    }
//    else
//    {
//        if(a%5==0 && x%5!=0)
//        return check(a+1,x,N,sum);
//        else{
//        sum+=a*x;
//        return check(a+1,x,N,sum);
//
//        }
//    }
//    return 0;
//}


int main(){

    long long t,N,tsum,n,p;
    scanf("%lld",&t);
    while(t--){
        tsum=0;
        scanf("%lld",&N);
        p=3;
        n=(N-1)/p;
        tsum+=(n*(p+n*p))/2;
        p=5;
        n=(N-1)/p;
        tsum+=(n*(p+n*p))/2;
        p=15;
        n=(N-1)/p;
        tsum-=(n*(p+n*p))/2;
        printf("%lld\n",tsum);
    }
    return 0;
}
