#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long findAnces(long long a, long long b, long long *h1,long long *h2){
    while(a!=b){
        while(a>b){
            a/=2;
            *h1*=2;
        }
        while(a<b){
            b/=2;
            *h2*=2;
        }
    }
    return a;
}

int main(){
    long long t,n,u,v;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&u,&v);
        long long h1=1,h2=1;
        long long anc=findAnces(u,v,&h1,&h2);
        if(h1>h2){
            h2=h1;
        }
        if(v>u){
            u=v;
        }
        printf("%lld\n",anc+(n-u)/h2);
    }
    return 0;
}
