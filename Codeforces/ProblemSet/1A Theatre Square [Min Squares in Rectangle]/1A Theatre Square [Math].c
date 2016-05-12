#include<stdio.h>

int main(){
	long long n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a);
	printf("%lld",(n/a+(n%a?1:0))*((m%a?1:0)+m/a));
	return 0;
}