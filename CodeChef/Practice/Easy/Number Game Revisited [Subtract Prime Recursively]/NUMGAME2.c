#include<stdio.h>

int main(){
    int t,num;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&num);
        printf("%s",num%4==1?"ALICE\n":"BOB\n");
    }
    return 0;
}
