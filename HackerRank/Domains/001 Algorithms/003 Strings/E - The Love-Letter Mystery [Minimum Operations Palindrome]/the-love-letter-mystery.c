#include<stdio.h>
#include<string.h>

int abso(int a){
    return a>0?a:-a;
}
int main(){
    int j,t,sum;
    char in[10002];
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        sum=0;
        k=strlen(in);
        for(j=0;j<k/2+k%2;j++){
            if(in[k-j-1]!=in[j]){
                sum+=abso(in[k-j-1]-in[j]);
            }
        }
        printf("%d\n",sum);
    }
    return 0;

}

