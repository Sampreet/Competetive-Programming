#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

int isPrime(long long m, long long root){
    long long i;
    if(m%2==0)
        return false;
    else{
        for(i=3;i<=root;i+=2){
            if(m%i==0 && m!=i)
                return false;
        }
        return true;
    }
}

int main(){

    long long t,N,p,i,a, primes[10000];
    scanf("%lld",&t);
    primes[0]=2;
    i=1;
    a=1;
    while(i<=10000){
        a+=2;
        p=sqrt(a);
        if(p%2==0)
            p--;
        if(isPrime(a,p)){
            primes[i]=a;
            i++;
        }
    }
    while(t--){
        scanf("%lld",&N);
        printf("%lld\n",primes[N-1]);
    }
    return 0;
}
