#include<stdio.h>

int main(){
    int k,j,t,n,p,a,cnt;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&p);
        a=n/k;
        cnt=a*k;
        j=1;
        while(a>=p){
            j=a/p;
            cnt=cnt+j*k;
            a=a-p*j+j;
        }
        printf("%d\n",cnt/k);
    }
    return 0;

}
