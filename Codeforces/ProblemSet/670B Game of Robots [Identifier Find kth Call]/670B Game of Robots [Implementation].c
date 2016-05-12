#include<stdio.h>

int main(){
	long long n,k,i,j=0;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++){
        j+=i;
        if(k<=j){
            break;
        }
	}
	j-=i;
	k-=j;
	for(i=0;i<k;i++){
        scanf("%lld",&j);
	}
	printf("%lld",j);
	return 0;
}
