#include<stdio.h>

int main(){
    int t,i,N,M,C,in,*jobs;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        jobs=(int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            jobs[i]=0;
        }
        while(M--){
            scanf("%d",&in);
            jobs[in-1]=1;
        }
        M=0;
        for(i=0;i<N;i++){
            if(jobs[i]==0){
                if(M%2==0){
                    printf("%d ",i+1);
                    jobs[i]=1;
                }
                M++;
            }
        }
        printf("\n");
        for(i=0;i<N;i++){
            if(jobs[i]==0){
                printf("%d ",i+1);
            }
        }
        printf("\n");
        free(jobs);
    }
    return 0;
}
