#include<stdio.h>

long long fribSum(long long a,long long b, long long N, long long sum){
    if(b>=N)
        return sum;
    else{
        sum+=b;
        return fribSum(a+b+b,b+b+b+a+a,N,sum);
    }
}

int main(){

    long long t,N,tsum,n,p;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&N);
        tsum=fribSum(1,2,N,0);
        printf("%lld\n",tsum);
    }
    return 0;
}
