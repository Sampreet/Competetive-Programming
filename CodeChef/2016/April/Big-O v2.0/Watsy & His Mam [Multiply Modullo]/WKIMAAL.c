#include<stdio.h>
#define MOD 1000000007

int main(){
	int t,N;
	long long sum,num;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		sum=1;
		while(N--){
			scanf("%lld",&num);
			sum=(sum*(num%MOD))%MOD;
		}
		printf("%lld\n",sum);
	}
	return 0;
}