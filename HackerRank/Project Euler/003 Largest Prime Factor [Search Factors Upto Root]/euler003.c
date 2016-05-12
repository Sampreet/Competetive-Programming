#include<stdio.h>
#include<math.h>

long long findGreatestPrimeFactor(long long m, long long root, long long pMax){
    long long i;
    if(m%2==0 & m!=2)
        return findGreatestPrimeFactor(m/2,root,m/2);
    else{
        for(i=3;i<=root;i+=2){
            if(m%i==0 && m!=i)
                return findGreatestPrimeFactor(m/i,root,m/i);
        }
        return pMax;
    }
}

int main(){

    long long t,N,p;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&N);
        p=sqrt(N);
        if(p%2==0)
            p--;
        p=findGreatestPrimeFactor(N,p,N);
        printf("%lld\n",p);
    }
    return 0;
}
