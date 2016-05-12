#include<stdio.h>
long long gcd(long long m, long long n)
{
   long long r;
   while(n!=0){
      r=m%n;
      m=n;
      n=r;
   }
   return m;
}
int main(){
    long long product,t,N,i;
    scanf("%lld",&t);
    while(t--){
        product=1;
        scanf("%lld",&N);
        for(i=1;i<=N;i++){
            product = product*i/gcd(product,i);
        }
        printf("%lld\n",product);
    }
}
