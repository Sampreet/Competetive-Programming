#include<stdio.h>
#include<stdlib.h>

int divide(int n,int k){
    while(n%k==0)
        n/=k;
    return n;
}

int isUgly(int n){
    n=divide(n,2);
    n=divide(n,3);
    n=divide(n,5);
    return (n==1)?1:0;
}

int nthUglyNum(int n){
    int count=1,i=1;
    while(count<n){
        i++;
        if(isUgly(i))
            count++;
    }
    return i;
}

int main(){
    int N,i;
    scanf("%d",&N);
    printf("%d",nthUglyNum(N));
    return 0;
}
