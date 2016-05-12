#include<stdio.h>
#include<stdlib.h>

int main(){
    int N,arr[100],x,i;
    char *helper[100];
    for(i=0;i<100;i++){
        helper[i]=malloc(12*sizeof(char));
        arr[i]=0;
    }
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&x);
        arr[x]++;
        if(i<N/2){
            scanf("%*s");
            helper[x]=realloc(helper[x],12*arr[x]*sizeof(char));
            helper[x][12*(arr[x]-1)]='-';
            helper[x][12*(arr[x]-1)+1]='\0';
        }
        else{
            helper[x]=realloc(helper[x],12*arr[x]*sizeof(char));
            scanf("%s",helper[x]+12*(arr[x]-1));
        }
    }
    for(x=0;x<100;x++){
        for(i=0;i<arr[x];i++){
            printf("%s ",helper[x]+12*(i));
        }
    }
    return 0;
}

