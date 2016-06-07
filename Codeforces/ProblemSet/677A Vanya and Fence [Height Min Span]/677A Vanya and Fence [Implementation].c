#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n,i,j,k,t,h;
    t=1;
    scanf("%d%d",&n,&h);
        k=n;
        for(i=0;i<n;i++){
            scanf("%d",&j);
            if(j>h){
                k++;
            }
        }
        printf("%d",k);
    return 0;
}
