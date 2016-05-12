#include<stdio.h>
#include<math.h>

int main(){
    char in[85]={0},*matrix;
    int L=0,r,c,i,j;
    ch=getchar()
    while(ch!=EOF){
        in[L]=ch;
        L++;
        ch=getchar();
    }
    r=sqrt(L);
    if(r*r==L){
        c=r;
    }
    else{
        c=r+1;
        if(r*c<L){
            r=r+1;
        }
    }
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            if(in[r*j+i]>0){
                printf("%c",in[r*j+i]);
            }
        }
        printf(" ");
    }
    return 0;
}
