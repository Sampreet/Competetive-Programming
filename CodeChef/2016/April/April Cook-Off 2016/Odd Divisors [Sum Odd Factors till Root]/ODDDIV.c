#include<stdio.h>
#include<math.h>

long long countDiv(int num, int root){
	long long sum=0;
	int i;
	for(i=1;i<=root;i++){
		if(i==root && root*root==num && i%2==1){
			sum+=i;
		}
		else if(num%i==0){
			if(i%2==1){
                sum+=i;
			}
			if((num/i)%2==1){
				sum+=num/i;
			}
		}
	}
	return sum;
}

int main(){

	int t,L,R,i;
	long long sum;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d%d",&L,&R);
		for(i=L;i<=R;i++){
			sum+=countDiv(i,sqrt(i));
		}
		printf("%lld\n",sum);
	}
	return 0;
}
