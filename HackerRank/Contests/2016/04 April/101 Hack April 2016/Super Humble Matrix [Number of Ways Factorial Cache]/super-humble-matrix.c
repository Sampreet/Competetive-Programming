#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MOD 1000000007

long long fact[1000001];

void init(){
    fact[0]=1;
    int i;
    for(i=1;i<=1000000;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

long long max(long long a,long long b){
    return a>b?a:b;
}

long long min(long long a,long long b){
    return a<b?a:b;
}

int main() {
    init();
    long long res,n,m,i,j;
    long long sum=1;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=min(n,m);i++){
        sum=(sum*fact[i])%MOD;
    }
    for(i=min(n,m)-1;i>0;i--){
        sum=(sum*fact[i])%MOD;
    }
    for(i=0;i<max(n,m)-min(n,m);i++){
        sum=(sum*fact[min(n,m)])%MOD;
    }
    printf("%lld",sum);
    return 0;
}
