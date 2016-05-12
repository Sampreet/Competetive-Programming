#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int maxSizeSubMat(int **mat,int R,int C){
    int S[R][C],i,j,max_s,max_i,max_j;
    for(i=0;i<R;i++)
        S[i][0]=mat[i][0];
    for(j=1;j<C;j++)
        S[0][j]=mat[0][j];
    for(i=1;i<R;i++){
        for(j=1;j<C;j++){
            if(mat[i][j]==0){
                S[i][j]=0;
            }
            else{
                S[i][j]=min3(S[i-1][j],S[i][j-1],S[i-1][j-1])+1;
            }
        }
    }
    max_s=S[0][0];
    max_i=0;
    max_j=0;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            //printf("%d ",S[i][j]);
            if(S[i][j]>max_s){
                max_s=S[i][j];
                max_i=i;
                max_j=j;
            }
        }
        //printf("\n");
    }
    return max_s;
}

int main(){
    int R,C,**mat,i,j;
    scanf("%d%d",&R,&C);
    mat=(int**)malloc(R*sizeof(int*));
    for(i=0;i<R;i++){
        mat[i]=(int*)malloc(C*sizeof(int));
        for(j=0;j<C;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("%d",maxSizeSubMat(mat,R,C));
    free(mat);
    return 0;
}
