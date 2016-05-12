#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647

typedef struct{
    int keys;
    int freq;
}pair;

int compare(const void *a,const void *b){
    return ((*(pair*)a).keys-(*(pair*)b).keys);
}

int sum(pair *data,int i,int j){
    int s=0,k;
    for(k=i;k<=j;k++)
        s+=data[k].freq;
    return s;
}

int minCostSearchTree(pair *data,int n){
    int cost[n][n],i,L,j,r,c;
    for(i=0;i<n;i++)
        cost[i][i]=data[i].freq;
    for(L=2;L<=n;L++){
        for(i=0;i<=n;i++){
            j=i+L-1;
            cost[i][j]=INT_MAX;
            for(r=i;r<=j;r++){
                c=((r>i)?cost[i][r-1]:0)+((r<j)?cost[r+1][j]:0)+sum(data,i,j);
                if(c<cost[i][j])
                    cost[i][j]=c;
            }
        }
    }
    return cost[0][n-1];
}

int main(){
    int N,i;
    pair *data;
    scanf("%d",&N);
    data=(pair*)malloc(N*sizeof(pair));
    for(i=0;i<N;i++){
        scanf("%d%d",&data[i].keys,&data[i].freq);
    }
    qsort(data,N,sizeof(pair),compare);
    printf("%d",minCostSearchTree(data,N));
    return 0;
}
