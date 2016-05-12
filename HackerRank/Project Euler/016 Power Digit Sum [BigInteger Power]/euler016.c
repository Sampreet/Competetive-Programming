#include<stdio.h>

typedef struct{
    int capacity;
    int dCount;
    unsigned char *digits;
} bigInteger;

void mult(int a,bigInteger *b){
    int carry=0,i,sum;
    for(i=0;i<b->dCount;++i){
        sum=a*b->digits[i]+carry;
        carry=sum/10;
        b->digits[i]=sum%10;
    }
    while(carry>0){
        sum=b->digits[b->dCount]+carry;
        carry=sum/10;
        b->digits[b->dCount]=sum%10;
        b->dCount++;
    }
}

bigInteger *exponentiate(int base,int power) {
    int p;
    bigInteger *result = malloc(sizeof(bigInteger));
    result->capacity=1+(int)(power*log10(base));
    result->digits=calloc(result->capacity, sizeof(unsigned char));
    result->digits[0]=1;
    result->dCount=1;

    for(p=0;p<power;p++){
        mult(base,result);
    }
    return result;
}


int main(){
    int t,i,N,sum;
    bigInteger *n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        n=exponentiate(2,N);
        sum=0;
        for(i=n->dCount-1;i>=0;--i){
            sum+=n->digits[i];
        }
        printf("%d\n",sum);
        free(n->digits);
        free(n);
    }
    return 0;
}
