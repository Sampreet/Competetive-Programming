#include<stdio.h>
#include<stdlib.h>

void display(int *arr,int N){
    int k;
    for(k=0;k<N;k++)
    {
        printf("%d ",arr[k]);
    }
    printf("\n");
}

void insertionSort(int *arr,int N){
    int i,temp,j;
    for(i=1;i<N;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main() {
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,N);
    display(arr,N);
    free(arr);
    return 0;
}
