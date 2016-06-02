#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 2147483647
#define MAX 10000

long long max(long long a, long long b){
	return a>b?a:b;
}

int myf(const void*a,const void*b){
    return *(long long*)a-*(long long*)b;
}

int main(){
	long long t,i,j,k,n,*arr;
	scanf("%lld",&t);
	while(t--){
        long long s=1,p=0;
		scanf("%lld",&n);
		arr=(long long*)malloc(n*sizeof(long long));
		for(i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
        qsort(arr,n,sizeof(long long), myf);
		for(i=1;i<n;i++){
            arr[i]+=arr[i-1];
		}
		p=arr[n-1];
		for(i=0;i<n;i++){
            if((i+2)*(arr[n-1]-arr[i])<p){
                break;
            }
            p=(i+2)*(arr[n-1]-arr[i]);
		}
		printf("%lld\n",p);
		free(arr);
	}
	return 0;
}
