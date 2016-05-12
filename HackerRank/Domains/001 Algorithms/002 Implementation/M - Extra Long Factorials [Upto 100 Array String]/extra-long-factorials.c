#include<stdio.h>

int main(){
    int t,i,N,sum,a,dCount,digits[200],carry;
    scanf("%d",&N);
    dCount=1;
    digits[0]=1;
    for(a=2;a<=N;a++){
        carry=0;
        for(i=0;i<dCount;i++){
            sum=a*digits[i]+carry;
            carry=sum/10;
            digits[i]=sum%10;
        }
        while(carry>0){
            sum=carry;
            carry=sum/10;
            digits[dCount]=sum%10;
            dCount++;
        }
    }
    for(i=dCount-1;i>=0;i--){
        printf("%d",digits[i]);
    }
    return 0;
}
