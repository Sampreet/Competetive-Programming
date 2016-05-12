#include<stdio.h>
#include<stdlib.h>

int longIncSub(int *arr,int len){
    int *lis,i,j,max=0;
    lis=(int*)malloc(len*sizeof(int));
    for(i=0;i<len;i++)
        lis[i]=1;
    max=lis[0];
    for(i=1;i<len;i++){
        for(j=0;j<i;j++)
            if(arr[j]<arr[i] && lis[j]+1>lis[i])
                lis[i]=lis[j]+1;
        if(lis[i]>max)
            max=lis[i];
    }
    free(arr);
    return max;
}

int main(){
    int N,i,ans=1,*arr;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    ans=longIncSub(arr,N);
    printf("%d\n",ans);
    return 0;
}
