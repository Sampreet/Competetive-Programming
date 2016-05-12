#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr,int N){
    int i,mark,temp,j,k;
    for(i=N-1;i>=0;i--)
    {
        mark=0;
        temp=arr[N-1];
        for(j=N-2;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                mark=1;
                arr[j+1]=arr[j];
                for(k=0;k<N;k++)
                {
                    printf("%d ",arr[k]);
                }
                printf("\n");
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
        if(mark==1)
        {
            for(k=0;k<N;k++)
            {
                printf("%d ",arr[k]);
            }
            printf("\n");
        }
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
    free(arr);
    return 0;
}
