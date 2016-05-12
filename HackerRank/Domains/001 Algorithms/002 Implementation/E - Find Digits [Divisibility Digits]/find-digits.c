#include<stdio.h>

int main(){
    int tot,t;
    long long a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&a);
        tot=0;
        b=a;
        while(a>0){
            if(a%10!=0 && b%(a%10)==0){
                tot++;
            }
            a=a/10;
        }
        printf("%lld\n",tot);
    }
    return 0;
}
