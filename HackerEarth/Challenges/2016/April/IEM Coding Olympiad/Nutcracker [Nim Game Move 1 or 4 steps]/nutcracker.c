#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,a,verd[10001]={};
    verd[0]=1;
    verd[2]=1;
    verd[3]=1;
    for(i=4;i<10001;i++){
        if(verd[i-1]==0 || verd[i-4]==0){
            verd[i]=1;
        }
    }
    scanf("%d",&a);
    while(a--){
        scanf("%d",&i);
        if(verd[i-1]==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
