#include<stdio.h>
#include<stdlib.h>

int longIncSub(int *arr,int len,int *max){
    if(len==1)
        return 1;
    int res,max_here=1,i;
    for(i=1;i<len;i++){
        res=longIncSub(arr,i,max);
        if(arr[i-1]<arr[len-1] && res+1>max_here)
            max_here=res+1;
    }
    if(*max<max_here)
        *max=max_here;
    return max_here;
}

int main(){
    int N,i,ans=1,*arr;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    longIncSub(arr,N,&ans);
    printf("%d\n",ans);
    return 0;
}
