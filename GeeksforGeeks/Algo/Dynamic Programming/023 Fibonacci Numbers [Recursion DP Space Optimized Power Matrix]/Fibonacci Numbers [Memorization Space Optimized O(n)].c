
#include<stdio.h>
#define MOD 1000000007

int fib(int n){
    int a,b,c,i;
    a=0;
    b=1;
    for(i=2;i<=n;i++){
        c=(a+b)%MOD;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%d",fib(N));
    return 0;
}
