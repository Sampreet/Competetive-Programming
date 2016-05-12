#include<stdio.h>
#include<stdlib.h>

int longIncSub(int *X,int N,int *S){
    int *P,*M;
    P=(int*)malloc(N*sizeof(int));
    M=(int*)malloc((N+1)*sizeof(int));
    int L=0,newL,lo,mid,hi,i,k;
    for(i=0;i<N;i++){
        lo=1;
        hi=L;
        while(lo<=hi){
             mid=(lo+hi)/2+(lo+hi)%2;
             if(X[M[mid]]<X[i])
                lo=mid+1;
             else
                hi=mid-1;
        }
        newL=lo;
        P[i]=M[newL-1];
        M[newL]=i;

        if(newL>L)
            L=newL;
    }
    k=M[L];
    for(i=L-1;i>=0;i--){
        S[i]=X[k];
        k=P[k];
    }
    return L;
}

int main(){
    int N,i,len=1,*arr,*finalArr;
    scanf("%d",&N);
    finalArr=(int*)malloc(N*sizeof(int));
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    len=longIncSub(arr,N,finalArr);
    printf("%d\n",len);
    for(i=0;i<len;i++){
        printf("%d ",finalArr[i]);
    }
    return 0;
}
