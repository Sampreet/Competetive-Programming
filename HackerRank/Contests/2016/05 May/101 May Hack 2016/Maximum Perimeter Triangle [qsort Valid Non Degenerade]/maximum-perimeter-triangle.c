#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000000
#define MOD 1000000007
#define INT_MIN -2147483648
#define INT_MAX 2147483647
typedef int bool;
#define true 1
#define false 0

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int mycmp(const void *a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(){
	int i,j,k,n,t;
	scanf("%d",&n);
	int *arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	qsort(arr,n,sizeof(int),mycmp);
	for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if(arr[k]+arr[j]>arr[i] && arr[i]-arr[k]<arr[j]){
                    printf("%d %d %d\n",arr[k],arr[j],arr[i]);
                    return 0;
                }
            }
        }
	}
	printf("-1");
	return 0;
}
