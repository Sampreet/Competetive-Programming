#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 2147483647
#define MAX 10000

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	long long t,i,j,k,n,l,*arr;
	t=1;
	while(t--){
		scanf("%lld",&n);
		if(n==2){
            printf("NO");
            return 0;
		}
		long long count=0,mark=0;
		for(i=0;i<n;i++){
			scanf("%lld",&k);
			if(k%2==1){
                if(mark==0){
                    l=i;
                    mark=1;
                }
                else{
                    count+=i-l;
                    count+=i-l;
                    mark=0;
                }
			}
		}
		if(mark==1){
            printf("NO");
            return 0;
		}
		else{
            printf("%lld",(count));
            return 0;
		}
	}
	return 0;
}
