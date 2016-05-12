#include<stdio.h>
#define MAX 1002
int main(){
    int N,K,t,maxi,i,j,multi;
    char numbers[MAX];
    scanf("%d",&t);
    while(t--){
        maxi=0;
        scanf("%d%d",&N,&K);
        scanf("%s",numbers);
        for(i=0;i<=N-K;i++){
            multi=1;
            for(j=i;j<i+K;j++){
                multi*=(numbers[j]-'0');
            }
            if(multi>maxi){
                maxi=multi;
            }
        }
        printf("%d\n",maxi);
    }
}
