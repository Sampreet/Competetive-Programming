#include<stdio.h>

int main(){
    long long t,N,M;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&M,&N);
        if(M==1 || N==1){
            if((M==1&&N==2)||(M==2&&N==1)){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            if(M%2!=0 && N%2!=0){
                printf("No\n");
            }
            else{
                printf("Yes\n");
            }
        }
    }
    return 0;
}
