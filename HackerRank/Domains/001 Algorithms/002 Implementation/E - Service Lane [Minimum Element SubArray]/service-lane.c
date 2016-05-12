#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n,*w,t,a,b,sum;
    scanf("%d%d",&n,&t);
    w=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    while(t--){
        scanf("%d%d",&a,&b);
        sum=3;
        for(i=a;i<=b;i++){
            if(w[i]<sum){
                sum=w[i];
            }
        }
        printf("%d\n",sum);
    }
    free(w);
    return 0;
}
