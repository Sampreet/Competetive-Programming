#include<stdio.h>

int main(){
    int i,*k,t,l,l2,sum,temp=0;
    scanf("%d",&t);
    k=(int *)malloc(t*sizeof(int));
    scanf("%d",&k[0]);
    l=k[0];
    temp=l;
    for(i=1;i<t;i++){
        scanf("%d",&k[i]);
        if(k[i]<l){
            l=k[i];
        }
        if(k[i]>temp)
            temp=k[i];
    }
    while(temp>0){
        sum=0;
        l2=temp;
        for(i=0;i<t;i++){
            if(k[i]>0){
                sum++;
                k[i]-=l;
            }
            if(k[i]<l2 && k[i]>0){
                l2=k[i];
            }
        }
        temp-=l;
        l=l2;
        if(sum==0){
            break;
        }
        else
            printf("%d\n",sum);
    }
    free(k);
    return 0;
}
