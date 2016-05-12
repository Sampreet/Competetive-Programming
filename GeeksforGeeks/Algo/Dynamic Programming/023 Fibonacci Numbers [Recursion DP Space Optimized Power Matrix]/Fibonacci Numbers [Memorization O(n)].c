#include<stdio.h>
#define MOD 1000000007

int fib(int n){
    int f[n+1],i;
    f[0]=0;
    f[1]=1;
    for(i=2;i<=n;i++){
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
    return f[n];
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%d",fib(N));
    return 0;
}
