#include<stdio.h>
#include<stdlib.h>

void merg(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merg(arr, l, m, r);
    }
}


int main(){
    int *arr,t,N,x,y,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&N,&a,&b);
        if(a==b){
            printf("%d\n",(N-1)*a);
        }
        else{
            arr=(int*)malloc(N*sizeof(int));
            for(x=0;x<N;x++){
                y=N-1-x;
                arr[x]=a*x+b*y;
            }
            mergeSort(arr,0,N-1);
            for(x=0;x<N;x++){
                printf("%d ",arr[x]);
            }
            printf("\n");
            free(arr);
        }
    }
    return 0;
}

