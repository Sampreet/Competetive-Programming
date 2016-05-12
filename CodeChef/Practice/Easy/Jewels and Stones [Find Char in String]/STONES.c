#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,i,j;
    char str[102];
    int count[52]={};
    scanf("%d",&t);
    while(t--){
        for(i=0;i<52;i++){
            count[i]=0;
        }
        scanf("%s",str);
        i=0;
        while(str[i]){
            if(str[i]<'a'){
                count[str[i]-'A']=1;
            }
            else{
                count[str[i]-'a'+26]=1;
            }
            i++;
        }
        scanf("%s",str);
        i=0;
        j=0;
        while(str[i]){
            if(str[i]<'a' && count[str[i]-'A']==1){
                j++;
            }
            if(str[i]>='a' && count[str[i]-'a'+26]==1){
                j++;
            }
            i++;
        }
        printf("%d\n",j);
    }
    return 0;
}
