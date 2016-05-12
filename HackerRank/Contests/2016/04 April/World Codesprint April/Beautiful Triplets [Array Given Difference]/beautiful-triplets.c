#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int bS(int *a,int lo,int hi,int key){
    if(lo<=hi){
        int mid=(lo+hi)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            return bS(a,lo,mid-1,key);
        }
        else{
            return bS(a,mid+1,hi,key);
        }
    }
    return -1;
}

int main() {
    int n,d,i,j,*c,ans=0;
    scanf("%d%d",&n,&d);
    c=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(c[i]-c[j]==d && bS(c,i+1,n-1,2*c[i]-c[j])!=-1){
                ans++;
            }
        }
    }
    printf("%d",ans);
    free(c);
    return 0;
}
