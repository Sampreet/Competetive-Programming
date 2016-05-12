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

int minCostSearchTree(pair *data,int i,int j){
    if(j<i)
        return 0;
    if(j==i)
        return data[i].freq;
    int fsum=sum(data,i,j),min=INT_MAX,r;
    for(r=i;r<=j;r++){
        int cost=minCostSearchTree(data,i,r-1)+minCostSearchTree(data,r+1,j);
        if(cost<min)
            min=cost;
    }
    return min+fsum;
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
    printf("%d",minCostSearchTree(data,0,N-1));
    return 0;
}
