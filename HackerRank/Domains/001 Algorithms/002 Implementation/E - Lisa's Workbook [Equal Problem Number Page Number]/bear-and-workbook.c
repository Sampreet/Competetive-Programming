#include<stdio.h>

int main() {
    int N,K;
    int i=1,j,in;
    int count=0;
    scanf("%d%d",&N,&K);
    while(N--){
        scanf("%d",&in);
        for(j=1;j<=in;j++){
            if((j-1)%K==0 && j!=1){
                i++;
            }
            if(j==i){
                count++;
            }
        }
        i++;
    }
	printf("%d",count);
    return 0;
}