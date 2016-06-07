#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 1000000
#define INT_MAX 2147483647

int main(){
    int n,i,j,k,t,*arr;
    scanf("%d",&t);
    while(t--){
        j=0;
        scanf("%d",&n);
        arr=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        if(n<3){
            printf("No\n");
            continue;
        }
        for(i=2;i<n;i++){
            if((arr[i]==arr[i-1] && arr[i-1]==arr[i-2])){
                printf("Yes\n");
                j=1;
                break;
            }
        }
        if(j==0) {
            printf("No\n");
        }
        free(arr);
    }
    return 0;
}
