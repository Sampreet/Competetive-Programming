#include<stdio.h>
#include<math.h>

long long divisorSum(long long number){
    long long a=2,sum=1,root=sqrt(number);
    while(a<=root){
        if(number%a==0){
            if(a*a==number){
                sum+=a;
            }
            else{
                sum+=a+number/a;
            }
        }
        a++;
    }
    return sum;
}

int main(){
    long long t,N,sum,temp=0,i,arr[305000];
    for(i=1;i<305000;i++){
        arr[i]=divisorSum(i);
    }
    scanf("%lld",&t);
    while(t--){
        sum=0;
        scanf("%lld",&N);
        for(i=1;i<N;i++){
            if(arr[arr[i]]==i && arr[i]>i){
                if(arr[i]<N)
                    sum+=arr[i]+i;
                else
                    sum+=i;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
