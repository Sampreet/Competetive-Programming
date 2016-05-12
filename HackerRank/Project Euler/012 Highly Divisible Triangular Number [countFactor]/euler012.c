#include<stdio.h>
#include<math.h>

long long countFactor(long long m){
    long long factorCount = 1, primeCount=0,i,root;
    root=sqrt(m);
    while(m%2==0){
        primeCount++;
        m=m/2;
    }
    factorCount*=primeCount+1;
    for(i=3;i<=root;i+=2){
        primeCount=0;
        while(m%i==0){
            m=m/i;
            primeCount++;
        }
        factorCount*=primeCount+1;
    }
    if(m!=1)
        return factorCount*2;
    return factorCount;
}


int main(){
    long long t,N,k,counter;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&N);
        k=1;
        counter=0;
        while(counter<=N){
            if(k%2==0)
                counter=countFactor(k/2)*countFactor(k+1);
            else
                counter=countFactor((k+1)/2)*countFactor(k);
            k++;
        }
        printf("%lld\n",((k-1)*k)/2);
    }
    return 0;
}
