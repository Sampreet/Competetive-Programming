#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
    return a>b?a:b;
}

int maxPalinSubSeq(char *str,int i,int j){
    if(i==j)
        return 1;
    if(i+1==j && str[i]==str[j])
        return 2;
    if(str[i]==str[j])
        return 2+maxPalinSubSeq(str,i+1,j-1);
    else
        return max(maxPalinSubSeq(str,i+1,j),maxPalinSubSeq(str,i,j-1));
}

int main(){
    char str[1002];
    scanf("%s",str);
    printf("%d",maxPalinSubSeq(str,0,strlen(str)-1));
    return 0;
}
