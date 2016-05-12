#include<stdio.h>
#include<stdlib.h>

struct pair{
    int a;
    int b;
};

int maxPairChainLen(struct pair *arr,int n){
    int i,j,max=0,mpcl[n];
    for(i=0;i<n;i++){
        mpcl[i]=1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++)
            if(arr[j].b<arr[i].a && mpcl[j]+1>mpcl[i])
                mpcl[i]=mpcl[j]+1;
    }
    for(i=0;i<n;i++)
        if(mpcl[i]>max)
            max=mpcl[i];
    return max;
}

int main(){
    int N,i;
    struct pair *p;
    scanf("%d",&N);
    p=(struct pair *)malloc(N*sizeof(struct pair));
    for(i=0;i<N;i++)
        scanf("%d%d",&p[i].a,&p[i].b);
    printf("%d",maxPairChainLen(p,N));
    free(p);
    return 0;
}
