#include<stdio.h>
#include<stdlib.h>

int max(int a,int b,int c){
    a=(a>b?a:b);
    return a>c?a:c;
}

int min(int a,int b,int c){
    a=(a<b?a:b);
    return a<c?a:c;
}

int main(){
    int n1,n2,n3,i,j,k,l,*arr1,*arr2,*arr3,*res,mini;
    scanf("%d%d%d",&n1,&n2,&n3);
    arr1=(int*)malloc(n1*sizeof(int));
    arr2=(int*)malloc(n2*sizeof(int));
    arr3=(int*)malloc(n3*sizeof(int));
    res=(int*)malloc(2*max(n1,n2,n3)*sizeof(int));
    for(i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<n3;i++){
        scanf("%d",&arr3[i]);
    }

    i=0;j=0;k=0;l=0;
    while(i<n1 && j<n2 && k<n3){
        //printf("%d %d %d\n",arr1[i],arr2[j],arr3[k]);
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
            res[l]=arr1[i];
            l++;
        }
        else if(arr1[i]==arr2[j] && arr2[j]!=arr3[k]){
            res[l]=arr1[i];
            l++;
            if(arr3[k]>arr2[j]){
                k--;
            }
        }
        else if(arr1[i]!=arr2[j] && arr2[j]==arr3[k]){
            res[l]=arr2[j];
            l++;
            if(arr1[i]>arr2[j]){
                i--;
            }
        }
        else if(arr1[i]==arr3[k] && arr2[j]!=arr3[k]){
            res[l]=arr1[i];
            l++;
            if(arr3[k]<arr2[j]){
                j--;
            }
        }
        else{
            mini=min(arr1[i],arr2[j],arr3[k]);
            if(arr1[i]==mini){
                j--;
                k--;
            }
            else if(arr2[j]==mini){
                i--;
                k--;
            }
            else{
                i--;
                j--;
            }
        }
        i++;
        j++;
        k++;
    }
    if(i==n1 && j!=n2 && k!=n3){
        while(j<n2 && k<n3){
            if(arr2[j]==arr3[k]){
                res[l]=arr2[j];
                l++;
            }
            else if(arr2[j]<arr3[k]){
                k--;
            }
            else{
                j--;
            }
            j++;k++;
        }
    }
    else if(i!=n1 && j==n2 && k!=n3){
        while(i<n1 && k<n3){
            if(arr1[i]==arr3[k]){
                res[l]=arr1[i];
                l++;
            }
            else if(arr1[i]<arr3[k]){
                k--;
            }
            else{
                i--;
            }
            i++;k++;
        }
    }
    else if(i!=n1 && j!=n2 && k==n3){
        while(i<n1 && j<n2){
            if(arr1[i]==arr2[j]){
                res[l]=arr1[i];
                l++;
            }
            else if(arr1[i]<arr2[j]){
                j--;
            }
            else{
                i--;
            }
            j++;i++;
        }
    }
    printf("%d\n",l);
    for(i=0;i<l;i++){
        printf("%d\n",res[i]);
    }
    return 0;
}
