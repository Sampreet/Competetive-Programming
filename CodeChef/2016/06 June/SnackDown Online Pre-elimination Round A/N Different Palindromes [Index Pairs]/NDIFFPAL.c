#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 10005
#define INT_MAX 2147483647

int main(){
    int n,i,j,k,t,*arr;
    scanf("%d",&t);
    while(t--){
        j=0;
        scanf("%d",&n);
        while(n--){
            printf("%c",'a'+n%26);
        }
        printf("\n");
    }
    return 0;
}
