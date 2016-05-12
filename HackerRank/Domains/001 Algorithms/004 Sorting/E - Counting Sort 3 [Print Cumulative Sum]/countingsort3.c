#include<stdio.h>

int main(){
    int N,arr[100]={0},x;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&x);
        arr[x]++;
        scanf("%*s");
    }
    for(x=0;x<100;x++){
        if(x==0)
            printf("%d ",arr[x]);
        else{
            arr[x]+=arr[x-1];
            printf("%d ",arr[x]);
        }
    }
    return 0;
}

