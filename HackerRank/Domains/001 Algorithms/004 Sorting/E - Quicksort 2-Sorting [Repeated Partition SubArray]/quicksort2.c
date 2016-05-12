#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int N){
    int k;
    for(k=0;k<N;k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
}

void partition(int *arr,int p,int N){
    int arr1[N],arr2[N],pivot=arr[p],i,countEqual=0,l1=0,l2=0;
    for(i=p;i<N;i++){
        if(arr[i]<pivot){
            arr1[l1]=arr[i];
            l1++;
        }
        else if(arr[i]>pivot){
            arr2[l2]=arr[i];
            l2++;
        }
        else{
            countEqual++;
        }
    }
    if(l1>1){
        partition(arr1,0,l1);
    }
    if(l2>1){
        partition(arr2,0,l2);
    }
    for(i=p;i<l1;i++){
        arr[i]=arr1[i];
    }
    for(i=p;i<countEqual;i++){
        arr[i+l1]=pivot;
    }
    for(i=p;i<l2;i++){
        arr[i+l1+countEqual]=arr2[i];
    }
    display(arr,l1+l2+countEqual);
}

int main() {
    int N,*arr,i;
    scanf("%d",&N);
    arr=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    partition(arr,0,N);
    free(arr);
    return 0;
}
