#include<stdio.h>
#define MOD 1000000007

int main(){
    int t,N,i;
    long long a=7,sum,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        k=1;
        sum=0;
        for(i=0;i<N;i++){
            sum=(sum+(a*(k%MOD)*((N-i)%MOD))%MOD)%MOD;
            k*=10;
            k%=MOD;
        }
        printf("%d\n",(int)(sum%MOD));
    }
    return 0;
}
