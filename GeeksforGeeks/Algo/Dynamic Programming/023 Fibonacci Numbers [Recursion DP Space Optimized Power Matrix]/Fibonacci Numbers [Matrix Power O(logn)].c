#include<stdio.h>
#define MOD 1000000007

void multiply(int F[2][2],int M[2][2]){
    long long x,y,z,w;
    x=((long long)F[0][0]*(long long)M[0][0]+(long long)F[0][1]*(long long)M[1][0])%MOD;
    y=((long long)F[0][0]*(long long)M[0][1]+(long long)F[0][1]*(long long)M[1][1])%MOD;
    z=((long long)F[1][0]*(long long)M[0][0]+(long long)F[1][1]*(long long)M[1][0])%MOD;
    w=((long long)F[1][0]*(long long)M[0][1]+(long long)F[1][1]*(long long)M[1][1])%MOD;
    F[0][0]=x;
    F[0][1]=y;
    F[1][0]=z;
    F[1][1]=w;
}

void power(int F[2][2],int n){
    if(n==0||n==1)
        return;
    int M[2][2]={{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    if(n%2!=0)
        multiply(F,M);
}

int fib(int n){
    int F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(F,n-1);
    return F[0][0];
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%d",fib(N));
    return 0;
}
