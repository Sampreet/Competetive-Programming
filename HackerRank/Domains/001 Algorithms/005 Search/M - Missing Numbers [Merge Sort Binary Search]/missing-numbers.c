#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *arr,int low,int high,int x){
    if(high>=low){
        int mid=low+(high-low)/2;
        if(x==arr[mid])
            return mid;
        if(x>arr[mid])
            return binarySearch(arr,(mid+1),high,x);
        else
            return binarySearch(arr,low,(mid-1),x);
    }
    return -1;
}

void merge(int *arr, int l, int m, int r){
    int i,j,k,n1=m-l+1,n2=r-m,L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int N1,N2,count[10001]={0},i,j,in,*arr,*arr2;
    scanf("%d",&N1);
    while(N1--){
        scanf("%d",&in);
        count[in]++;
    }
    scanf("%d",&N2);
    arr2=(int*)malloc(N2*sizeof(int));
    arr=(int*)malloc(N2*sizeof(int));
    j=0;
    for(i=0;i<N2;i++){
        scanf("%d",&arr2[i]);
    }
    mergeSort(arr2,0,N2-1);
    for(i=0;i<N2;i++){
        in=arr2[i];
        if(count[in]==0 && binarySearch(arr,0,j-1,in)==-1){
            arr[j]=in;
            j++;
        }
        else{
            count[in]--;
        }
    }
    for(i=0;i<j;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
