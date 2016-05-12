#include<stdio.h>

int main(){
    long long t,N;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&N);
        printf("%lld\n",(3*N*N*N*N+2*N*N*N-3*N*N-2*N)/12);
    }
}
