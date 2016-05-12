#include<stdio.h>

int main(){
    int t,i,mark;
    char str[102];
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        i=0;
        mark=0;
        while(str[i]){
            if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U'){
                mark=1;
                printf("yes\n");
                break;
            }
            i++;
        }
        if(mark==0){
            printf("no\n");
        }
    }
    return 0;
}
