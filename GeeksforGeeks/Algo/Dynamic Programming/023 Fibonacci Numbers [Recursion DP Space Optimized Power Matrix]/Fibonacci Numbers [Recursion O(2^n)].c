#include<stdio.h>
#define MOD 1000000007
int fib(int n){
    if(n<=1)
        return n;
    return (fib(n-1)+fib(n-2))%MOD;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}
