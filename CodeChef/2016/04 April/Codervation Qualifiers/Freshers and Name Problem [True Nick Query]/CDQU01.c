#include<stdio.h>
#include<string.h>

struct db{
    char tname[102];
    char nname[102];
};

int main(){
    int N,Q,i,mark;
    char query[102];
    struct db *d;
    scanf("%d%d",&N,&Q);
    d=(struct db*)malloc(N*sizeof(struct db));
    for(i=0;i<N;i++){
        scanf("%s%s",d[i].tname,d[i].nname);
    }
    for(i=0;i<Q;i++){
        scanf("%s",query);
        int j,mark=0;
        for(j=0;j<N;j++){
            if(!strcmp(d[j].nname,query)){
                printf("%s\n",d[j].tname);
                mark=1;
                break;
            }
        }
        if(mark==0){
            printf("Name not found\n");
        }
    }
    return 0;
}
