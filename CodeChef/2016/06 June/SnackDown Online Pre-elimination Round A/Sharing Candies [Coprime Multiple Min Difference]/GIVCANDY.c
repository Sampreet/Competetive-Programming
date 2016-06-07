#include<stdio.h>
#include<stdlib.h>

long long abso(long long a){
    return a>0?a:-a;
}

long long min(long long a, long long b){
    return a<b?a:b;
}

long long gcd(long long m,long long n){
    long long r;
    if(m<n){
        r=m;
        m=n;
        n=r;
    }
    while(n) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main(){
    int n,i,j,k,t,*arr;
    long long a,b,c,d;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        long long g=gcd(c,d),diff=abso(a-b);
        long long mindiff;
        if(g==1){
            printf("0\n");
        }
        else{
            mindiff = diff/g;
            mindiff = min(abso(diff-g*mindiff),abso(diff-g*(mindiff+1)));
            printf("%lld\n",mindiff);
        }
    }
    return 0;
}
