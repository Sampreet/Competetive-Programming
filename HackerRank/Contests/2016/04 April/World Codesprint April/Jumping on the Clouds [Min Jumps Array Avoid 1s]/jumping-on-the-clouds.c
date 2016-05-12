#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j=0,k; 
    scanf("%d",&n);
    int c, cnt=-1;
    for(i=0;i<n;i++){
        scanf("%d",&c);
        if(c==1){
            cnt+=1+j/2;
            j=0;
        }
        else{
            j++;
        }
    }
    cnt+=1+j/2;
    printf("%d",cnt);
    return 0;
}
