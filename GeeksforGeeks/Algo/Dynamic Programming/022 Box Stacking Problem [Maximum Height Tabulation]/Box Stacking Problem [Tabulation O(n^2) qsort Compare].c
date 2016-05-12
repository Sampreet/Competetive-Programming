#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int h,w,d;
}Box;

int min(int x,int y){
    return x<y?x:y;
}

int max(int x,int y){
    return x>y?x:y;
}

int compare(const void *a,const void *b){
    return ((*(Box*)b).d*(*(Box*)b).w)-((*(Box*)a).d*(*(Box*)a).w);
}

int maxStackHeight(Box *arr,int n){
    Box rot[3*n];
    int i,index=0,j,maxi,msh[3*n];
    for(i=0;i<n;i++){
        rot[index]=arr[i];
        index++;
        rot[index].h=arr[i].w;
        rot[index].d=max(arr[i].h,arr[i].d);
        rot[index].w=min(arr[i].h,arr[i].d);
        index++;
        rot[index].h=arr[i].d;
        rot[index].d=max(arr[i].h,arr[i].w);
        rot[index].w=min(arr[i].h,arr[i].w);
        index++;
    }
    n=3*n;
    qsort(rot,n,sizeof(rot[0]),compare);
    for(i=0;i<n;i++)
        msh[i]=rot[i].h;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++){
            if(rot[i].w<rot[j].w && rot[i].d<rot[j].d && msh[i]<msh[j]+rot[i].h)
                msh[i]=msh[j]+rot[i].h;
        }
    maxi=-1;
    for(i=0;i<n;i++)
        maxi=max(maxi,msh[i]);
    return maxi;
}

int main(){
    int i,j,N;
    Box *arr;
    scanf("%d",&N);
    arr=(Box*)malloc(N*sizeof(Box));
    for(i=0;i<N;i++){
        scanf("%d%d%d",&arr[i].h,&arr[i].w,&arr[i].d);
    }
    printf("%d",maxStackHeight(arr,N));
    free(arr);
    return 0;
}
