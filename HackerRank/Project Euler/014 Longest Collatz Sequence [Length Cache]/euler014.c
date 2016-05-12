#include<stdio.h>
#define MAX 5000000
long long cache[MAX]={0};
long long index[MAX];
long long findSequenceLength(long long n){
    long long countLen=0;
    while(n!=1){

        if(n<=MAX && cache[n-1]!=0){
            countLen+=cache[n-1];
            //printf("%lld %lld %lld\n",n,cache[n-1],countLen);
            n=1;

        }
        else{
            if(n%2==0){
                n=n/2;
                countLen++;
                // printf("%lld %lld %lld\n",n,cache[n-1],countLen);
            }
            else{
                n=3*n+1;
                countLen++;
                //printf("%lld %lld %lld\n",n,cache[n-1],countLen);
            }
        }
    }
    return countLen;
}

int main(){
    long long t,N,i,maxi=0,ind=1,len;
    scanf("%lld",&t);
    maxi=0;
    for(N=1;N<=MAX;N++){
        cache[N-1]=findSequenceLength(N);
        if(cache[N-1]>=maxi){
            maxi=cache[N-1];
            ind=N;
        }
        index[N-1]=ind;
    }
    while(t--){
        scanf("%lld",&N);
        printf("%lld\n",index[N-1]);
    }
    return 0;
}
