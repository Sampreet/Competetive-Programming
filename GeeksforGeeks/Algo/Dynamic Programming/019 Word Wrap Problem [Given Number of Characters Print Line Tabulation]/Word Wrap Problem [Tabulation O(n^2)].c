#include<stdio.h>
#include<stdlib.h>
#define INF 2147483647

int printSol(int p[],int n){
    int k;
    if(p[n]==1){
        k=1;
    }
    else{
        k=printSol(p,p[n]-1)+1;
    }
    printf("Line Number %d: Index %d to %d\n",k,p[n],n);
    return k;
}

void wordWrap(int *l,int n,int M){
    int extras[n+1][n+1],lc[n+1][n+1],C[n+1],p[n+1],i,j;
    for(i=1;i<=n;i++){
        extras[i][i]=M-l[i-1];
        for(j=i+1;j<=n;j++){
            extras[i][j]=extras[i][j-1]-l[j-1]-1;
        }
    }
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++){
            if(extras[i][j]<0)
                lc[i][j]=INF;
            else if(j==n && extras[i][j]>=0)
                lc[i][j]=0;
            else
                lc[i][j]=extras[i][j]*extras[i][j];
        }
    C[0]=0;
    for(j=1;j<=n;j++){
        C[j]=INF;
        for(i=1;i<=j;i++){
            if(C[i-1]!=INF && lc[i][j]!=INF && C[i-1]+lc[i][j]<C[j]){
                C[j]=C[i-1]+lc[i][j];
                p[j]=i;
            }
        }
    }
    printSol(p,n);
}
int main(){
    int *line,N,M,i;
    scanf("%d%d",&N,&M);
    line=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
        scanf("%d",&line[i]);
    wordWrap(line,N,M);
    free(line);
    return 0;
}
