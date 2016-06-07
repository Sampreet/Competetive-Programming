#include<stdio.h>
#define MOD 1000000007
 
unsigned long long power(unsigned long long base,unsigned long long exp){
    unsigned long long res=1;
    base%=MOD;
    while(exp>0){
        if(exp%2==1){
            res=(res*base)%MOD;
        }
        base=(base*base)%MOD;
        exp/=2;
    }
    return res%MOD;
}
int main(){
    unsigned long long t,n,k,temp;
    scanf("%llu",&t);
    while(t--){
        scanf("%llu%llu",&n,&k);
		temp=power(k-1,n-1);
        k%=MOD;
		temp=temp*k;
		temp%=MOD;
		printf("%llu\n",temp);
    }
    return 0;
}