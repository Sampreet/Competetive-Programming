#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char s[200005];
    int i=1,j=0,k=0,m,n;
    int count=0;
    scanf("%s",s);
    while(s[i]){
        if(s[i-1]==s[i]){
            j++;
        }
        else{
            //printf("%d %d\n",k,j);
            for(m=k+1;m<=j;m+=2){
                if(s[m+1]!='\0'){
                    s[m]='a'+(s[m-1]-'a'+1)%26;
                    if(s[m]==s[m+1]){
                        s[m]='a'+(s[m]-'a'+1)%26;
                    }
                }
                else{
                    if(s[m]==s[m-1]){
                        s[m]='a'+(s[m-1]-'a'+1)%26;
                    }
                }
            }
            j=i;
            k=i;
        }
        i++;
    }
    for(m=k+1;m<=j;m+=2){
        if(s[m+1]!='\0'){
            s[m]='a'+(s[m-1]-'a'+1)%26;
            if(s[m]==s[m+1]){
                s[m]='a'+(s[m]-'a'+1)%26;
            }
        }
        else{
            if(s[m]==s[m-1]){
                s[m]='a'+(s[m-1]-'a'+1)%26;
            }
        }
    }
    printf("%s",s);
    return 0;
}
