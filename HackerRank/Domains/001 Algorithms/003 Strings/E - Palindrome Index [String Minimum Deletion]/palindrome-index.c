#include<stdio.h>
#include<string.h>

int isPalindrome(char *str,int start,int end){
    if(start>end){
        return 0;
    }
    while(start<end){
        if(str[start]!=str[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main(){
    int index,t,start,end;
    char str[100007];
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        start=0;
        end=strlen(str)-1;
        while(str[start]==str[end]){
            start++;
            end--;
            if(start>=end){
                index=-1;
                break;
            }
        }
        if(start<end){
            if(isPalindrome(str,start+1,end)){
                index=start;
            }
            if(isPalindrome(str,start,end-1)){
                index=end;
            }
        }
        printf("%d\n",index);
    }
    return 0;
}
