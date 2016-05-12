#include<stdio.h>
#define NIL -1
#define MAX 10000
#define MOD 1000000007

long long fibo[MAX+1];

void _initialize(){
    int i;
    for(i=0;i<MAX+1;i++){
        fibo[i]=NIL;
    }
}

long long findFibo(int N){
    if(N<2){
        fibo[N]=N;
    }
    fibo[N]=((fibo[N-1]==NIL?findFibo(N-1):fibo[N-1])%MOD+(fibo[N-2]==NIL?findFibo(N-2):fibo[N-2])%MOD)%MOD;
    return fibo[N];
}

int main(){
    int N;
    _initialize();
    scanf("%d",&N);
    printf("%lld",findFibo(N));
    return 0;
}
