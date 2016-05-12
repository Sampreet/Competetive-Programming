#include<stdio.h>
#define NIL -1
#define MAX 10000
#define MOD 1000000007

long long findFibo(int N){
    long long fibo[N+1];
    int i;
    fibo[0]=0;
    fibo[1]=1;
    for(i=2;i<=N;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%MOD;
    }
    return fibo[N];
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%lld",findFibo(N));
    return 0;
}
