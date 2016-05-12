#include<stdio.h>
#include<stdlib.h>

long long res=0;

void merge(int *array,int lhs,int mid,int rhs){
    int *tmp,i=lhs,j=mid+1,k=0;
    tmp=malloc((rhs-lhs+1)*sizeof(int));
    while(i<=mid && j<=rhs){
        if(array[i] <= array[j]){
            tmp[k++]=array[i++];
        }
        else{
            res+=mid-i+1;
            tmp[k++] = array[j++];
        }
    }
    while(i<=mid)
        tmp[k++]=array[i++];
    while(j<=rhs)
        tmp[k++]=array[j++];
    for(i=0;i<k;i++)
        array[lhs+i]=tmp[i];
    free(tmp);
}

void mergeCount(int *array,int lhs,int rhs){
    if(lhs<rhs){
        int mid=lhs+(rhs-lhs)/2;
        mergeCount(array,lhs,mid);
        mergeCount(array,mid+1,rhs);
        merge(array,lhs,mid,rhs);
    }
}


int main() {
    int N,*arr,i,t;
    scanf("%d",&t);
    while(t--){
        res=0;
        scanf("%d",&N);
        arr=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        mergeCount(arr,0,N-1);
        printf("%lld\n",res);
        free(arr);
    }
    return 0;
}
