#include<stdio.h>

int main(){
    int i,t;
    char ch;
    scanf("%d%*c",&t);
    while(t--){
        int mark=0;
        while(scanf("%c",&ch)!=EOF){
            if(ch=='\n'){
                printf("\n");
                break;
            }
            else if(ch<='z'&&ch>='a'){
                if(mark==1){
                    printf("-");
                }
                else if(mark==2){
                    printf("$");
                }
                mark=1;
                printf("%d",(int)((ch-'a')*(ch-'a')));
            }
            else{
                mark=2;
            }
        }
    }
}
