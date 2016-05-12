#include<stdio.h>
#include<stdlib.h>

void rotate_ring(int **matrix, int m, int n, int rot, int ring_number){
    int *ring;
    int left=ring_number;
    int right=n-1-ring_number;
    int upper=ring_number;
    int lower=m-1-ring_number;
    int N=2*(right-left+lower-upper),i;
    rot=rot%N;
    ring=(int*)malloc(N*sizeof(int));
    for(i=left;i<=right;i++){
        ring[i-left]=matrix[upper][i];
    }
    for(i=upper;i<=lower;i++){
        ring[right-left+i-upper]=matrix[i][right];
    }
    for(i=right;i>=left;i--){
        ring[right-left+lower-upper-i+right]=matrix[lower][i];
    }
    for(i=lower;i>upper;i--){
        ring[2*(right-left)+lower-upper-i+lower]=matrix[i][left];
    }
    for(i=left;i<=right;i++){
        matrix[upper][i]=ring[(i-left+rot)%N];
    }
    for(i=upper;i<=lower;i++){
        matrix[i][right]=ring[(right-left+i-upper+rot)%N];
    }
    for(i=right;i>=left;i--){
        matrix[lower][i]=ring[(right-left+lower-upper-i+right+rot)%N];
    }
    for(i=lower;i>upper;i--){
        matrix[i][left]=ring[(2*(right-left)+lower-upper-i+lower+rot)%N];
    }
    free(ring);
}

int main(){
    int M,N,i,j,**matrix,rot;
    scanf("%d%d%d",&M,&N,&rot);
    matrix=(int**)malloc(M*sizeof(int*));
    for(i=0;i<M;i++){
        matrix[i]=(int*)malloc(N*sizeof(int));
        for(j=0;j<N;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int rings=M;
    if(N<M){
        rings=N;
    }
    rings/=2;
    for(i=0;i<rings;i++){
        rotate_ring(matrix,M,N,rot,i);
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    free(matrix);
    return 0;
}
