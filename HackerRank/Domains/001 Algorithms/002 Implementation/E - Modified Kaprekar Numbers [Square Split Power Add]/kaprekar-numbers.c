#include<stdio.h>

int isKaprekar(long long a){
    if(a==1)
        return 1;
    long long square=a*a,temp,k=0;
    temp=square;
    while(temp>0){
        temp/=10;
        k++;
    }
    k=k/2+k%2;
    temp=1;
    while(k>0){
        temp*=10;
        k--;
    }
    if(square%temp+square/temp==a)
        return 1;
    else
        return 0;
}

int main(){
    long long a,b,counter=0;
    scanf("%lld%lld",&a,&b);
    while(a<=b){
        if(isKaprekar(a)){
            counter++;
            printf("%lld ",a);
        }
        a++;
    }
    if(counter==0){
        printf("INVALID RANGE");
    }
}
