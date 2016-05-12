#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,G,in,q,N;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&G);
		while(G--){
			scanf("%d%d%d",&in,&N,&q);
			if(N%2==0){
				printf("%d\n",N/2);
			}
			else{
				if(in==q){
					printf("%d\n",N/2);
				}
				else{
					printf("%d\n",N/2+1);
				}
			}
		}
	}
	return 0;
}
