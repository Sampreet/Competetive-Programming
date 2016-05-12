#include<stdio.h>
#include<stdlib.h>
#define INF 9999

int min(int a,int b){
    return a<b?a:b;
}

void printDist(int **dist,int V){
    int i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

void minVertDist(int **graph,int V){
    int **dist,i,j,k;
    dist=(int**)malloc(V*sizeof(int*));
    for(i=0;i<V;i++){
        dist[i]=(int*)malloc(V*sizeof(int));
        for(j=0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            for(k=0;k<V;k++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    printDist(dist,V);
    free(dist);
}

int main(){
    int **graph,V,i,j;
    scanf("%d",&V);
    graph=(int**)malloc(V*sizeof(int*));
    for(i=0;i<V;i++){
        graph[i]=(int*)malloc(V*sizeof(int));
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    minVertDist(graph,V);
    return 0;
}
