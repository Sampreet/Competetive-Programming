#include<stdio.h>
#include<math.h>

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


int divisorSum(int number){
    int a=2,sum=1,root=sqrt(number);
    while(a<=root){
        if(number%a==0){
            if(a*a==number){
                sum+=a;
            }
            else{
                sum+=a+number/a;
            }
        }
        a++;
    }
    return sum;
}

int main(){
    int t,N,temp=0,i,arr[100001],j=0;
    for(i=1;i<100001;i++){
        if(divisorSum(i)>i){
           arr[j]=i;
           j++;
        }
    }
    mergeSort(arr,0,j-1);
    scanf("%d",&t);
    while(t--){
        temp=0;
        scanf("%d",&N);
        for(i=0;i<j;i++){
            if(arr[i]<N){
                if(binarySearch(arr,i,j-1,N-arr[i])!=-1){
                    printf("YES\n");
                    temp=1;
                    break;
                }
            }
            else
                break;
        }
        if(temp==0)
            printf("NO\n");
    }
    return 0;
}
