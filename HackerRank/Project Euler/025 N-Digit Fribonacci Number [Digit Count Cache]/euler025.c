#include<stdio.h>
#include<stdlib.h>

int nextFriboDigitCount(int *arr1,int *arr2,int j){
    int i=0,carry=0,arr3[5002];
    for(i=0;i<5002;i++){
        arr3[i]=arr1[i];
    }
    i=0;
    while(i!=j){
        arr1[i]+=arr2[i]+carry;
        carry=arr1[i]/10;
        arr1[i]=arr1[i]%10;
        i++;
    }
    while(carry>0){
        arr1[i]+=carry%10;
        carry/=10;
        i++;
    }
    for(j=0;j<5002;j++){
        arr2[j]=arr3[j];
    }
    return i;
}

int main(){
    int arr1[5002],arr2[5002],t,N,i,j,n;
    long long ans[5001],res;
    ans[0]=0;
    ans[1]=1;
    for(i=0;i<5002;i++){
        arr1[i]=0;
        arr2[i]=0;
    }
    arr1[0]=1;
    arr2[0]=1;
    i=1;
    j=1;
    res=2;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(n=i+1;n<=N;n++){
            while(i<n){
                res++;
                i=nextFriboDigitCount(arr2,arr1,j);
                j=i;
            }
            ans[n]=res;
        }
        printf("%lld\n",ans[N]);

    }
    return 0;
}
