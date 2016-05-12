#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define true 1
#define false 0

int arr[1000001];

int isPrime(int m, int root){
    int i;
    if(m%2==0)
        return false;
    else{
        for(i=3;i<=root;i+=2){
            if(m%i==0 && m!=i)
                return false;
        }
        return true;
    }
}

int main(){
    int t,n,m,i,j,k,q;
    scanf("%d",&n);
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    for(i=3;i<1000001;i++){
        if(isPrime(i,sqrt(i))){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d",&m);
        if(arr[m]>0){
            arr[m]++;
        }

    }
    for(i=1;i<1000001;i++){
        if(arr[i]>0){
            arr[i]=arr[i-1]+arr[i]-1;
        }
        else{
            arr[i]=arr[i-1];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&i,&j);
        printf("%d\n",arr[j]-arr[i-1]);
    }
    return 0;
}
