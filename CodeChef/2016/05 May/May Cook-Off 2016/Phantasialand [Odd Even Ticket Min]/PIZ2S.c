#include<stdio.h>

int main(){
    int t,in,i,sum=0;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&in);
        sum+=in;
    }
    int ans = sum%2+sum/2;
    printf("%d",ans>t?ans:t);
    return 0;
}
