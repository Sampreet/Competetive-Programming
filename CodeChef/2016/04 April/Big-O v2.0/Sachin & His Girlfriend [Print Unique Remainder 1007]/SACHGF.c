#include<stdio.h>

int main(){
	int t,N;
	int arr[1007]={};
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		if(arr[N%1007]==0){
			arr[N%1007]++;
			printf("%d\n",N%1007);
		}	
	}
	return 0;
}