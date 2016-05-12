#include<stdio.h>
#include<stdlib.h>

void update(int *p, int k, int *ind){
    int i=ind[k-1],temp=p[ind[k-1]];
    for(i=ind[k-1]-1;i>=0;i--){
        p[i+1]=p[i];
        ind[p[i+1]-1]=i+1;
    }
    p[0]=temp;
    ind[k-1]=0;
}

int main(){
    int *p,*index;
    int n,m,k,s;
    int res=0;
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    p=(int*)malloc(k*sizeof(int));
    index=(int*)malloc(k*sizeof(int));
    for(i=0;i<k;i++){
        scanf("%d",&p[i]);
        index[p[i]-1]=i;
    }
    s=k;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&k);
            res+=index[k-1]+1;
            update(p,k,index);

        }
    }
    free(p);
    free(index);
    printf("%d\n",res);
    return 0;
}
