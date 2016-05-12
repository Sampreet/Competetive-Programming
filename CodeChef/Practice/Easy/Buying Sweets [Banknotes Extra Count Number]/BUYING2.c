#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

int main(){
    int i,k,n,*a,min,t;
    long long sum=0;
    scanf("%d",&t);
    while(t--){
        sum=0;
        min=INT_MAX;
        scanf("%d%d",&n,&k);
        a=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            min=(a[i]<min?a[i]:min);
            sum+=a[i];
        }
        if(sum%k==0){
            printf("%lld\n",sum/k);
        }
        else{
            if((long long)min>sum%k){
                printf("%lld\n",sum/k);
            }
            else{
                printf("-1\n");
            }
        }
    }
    return 0;
}
