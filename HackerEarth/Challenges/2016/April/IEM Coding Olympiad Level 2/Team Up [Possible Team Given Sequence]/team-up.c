#include<stdio.h>
#include<stdlib.h>

int x[1000000];

int cmp(const void *a, const void *b){
    return *(int*)a<*(int*)b?1:0;
};

int main(){
    int N,t,a,b,c,m,i,j,k,mark;
    scanf("%d",&t);
    x[0]=0;
    while(t--){
        scanf("%d%d%d%d%d",&N,&a,&b,&c,&m);
        mark=0;
        x[0]=c;
        for(i=1;i<N;i++){
            x[i]=(a*(x[i-1]-c)+b)%m;
            x[i]+=c;
            if(x[i]>=N){
                mark=1;
                break;
            }
        }
        if(mark==0){
            qsort(x,N,sizeof(int),cmp);
        }
        for(i=0;i<N-1;i++){
            if(x[i]==0){
                continue;
            }
            for(j=i+1;j<N;j++){
                if(x[j]>0){
                    x[j]--;
                    x[i]--;
                }
                if(x[i]==0){
                    break;
                }
            }
            if(x[i]>0){
                mark=1;
                break;
            }
        }
        if(x[N-1]>0){
            mark=1;
        }
        if(mark==0){
            printf("LIKE\n");
        }
        else{
            printf("DISLIKE\n");
        }
    }
    return 0;
}
