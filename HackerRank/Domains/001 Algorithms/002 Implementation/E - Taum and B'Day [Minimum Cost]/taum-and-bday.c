#include<stdio.h>

long long minima(long long a,long long b){
    return a<b?a:b;
}

int main(){
    long long t,b,w,x,y,z,i,j;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld",b,w,x,y,z);
        i=minima(x,y+z);
        j=minima(x+z,y);
        printf("%lld\n",b*i+w*j);
    }
    return 0;
}
