#include<stdio.h>

int main(){
    char sum[55]={0},in[52],m;
    int N,i,mark=0;
    scanf("%d",&N);
    while(N--){
        scanf("%s",in);
        for(i=49;i>=0;i--){
            sum[49-i]+=in[i]-'0';
            while(sum[49-i]>9){
                sum[49-i+1]++;
                sum[49-i]-=10;
            }
        }
        while(sum[50]>9){
            sum[51]++;
            sum[50]-=10;
        }
        while(sum[51]>9){
            sum[52]++;
            sum[51]-=10;
        }
        while(sum[52]>9){
            sum[53]++;
            sum[52]-=10;
        }
    }
    if(sum[53]!=0)
        mark=3;
    else{
        if(sum[52]!=0)
            mark=2;
        else{
            if(sum[51]!=0)
                mark=1;
            else{
                if(sum[50]!=0)
                    mark=0;
                else
                    mark=-1;
            }
        }
    }
    for(i=50+mark;i>50+mark-10;i--){
        printf("%d",sum[i]);
    }
    return 0;
}
