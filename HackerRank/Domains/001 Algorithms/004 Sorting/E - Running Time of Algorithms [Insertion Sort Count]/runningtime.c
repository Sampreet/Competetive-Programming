#include<stdio.h>
#include<stdlib.h>

int insertionCount(int *arr,int N){
    int i,temp,j,count=0;
    for(i=1;i<N;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            count++;
            j--;
        }
        arr[j+1]=temp;
    }
    return count;
}

int main() {
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",insertionCount(arr,N));
    free(arr);
    return 0;
}
