#include<stdio.h>
#include<stdlib.h>

int count2=0;

int insertionSort(int *arr,int N){
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

int partition(int *arr,int low,int high){
    int pivot=arr[high],i=low,j,temp;
    for(j=low;j<high;j++){
        if(arr[j]<=pivot){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            count2++;
        }
    }
    temp=arr[i];
    arr[i]=arr[high];
    arr[high]=temp;
    count2++;
    return i;
}

void quickSort(int *arr,int low,int high,int N){
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1,N);
        quickSort(arr,p+1,high,N);
    }
}

int main(){
    int i,*arr1,*arr2,N;
    scanf("%d",&N);
    arr1=(int*)malloc(N*sizeof(int));
    arr2=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",&arr1[i]);
        arr2[i]=arr1[i];
    }
    quickSort(arr2,0,N-1,N);
    printf("%d",insertionSort(arr1,N)-count2);
    free(arr1);
    free(arr2);
    return 0;
}
