#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,t,n,*arr,c1,c2;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==1){
            scanf("%d",&i);
            printf("YES\n");
            continue;
        }
        arr=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        c1=0;
        c2=0;
        for(i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                c1++;
            }
        }
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    c2++;
                }
            }
        }
        if(c1==c2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
