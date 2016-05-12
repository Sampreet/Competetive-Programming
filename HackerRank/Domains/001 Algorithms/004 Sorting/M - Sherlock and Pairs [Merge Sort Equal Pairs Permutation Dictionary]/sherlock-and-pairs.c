#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int l, int m, int r)
{
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

void mergeSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    int N,i,j,t,*arr;
    long long sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        arr=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        mergeSort(arr,0,N-1);
        sum=0;
        i=0;
        j=1;
        while(i<N){
            j=i+1;
            while(j<N && arr[j]==arr[j-1]){
                j++;
            }
            sum+=(long long)(j-i)*(long long)(j-1-i);
            i=j;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
