#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,n,i,j,k,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d",&k);
        j=1;
        for(i=1;i<n;i++){
            scanf("%d",&l);
            if(l<=k){
                j++;
                k=l;
            }
        }
        printf("%d\n",j);
    }
    return 0;
}
