#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int editDist(char *s1,char *s2,int m,int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(s1[m-1]==s2[n-1]){
        return editDist(s1,s2,m-1,n-1);
    }
    else{
        return 1+min3(editDist(s1,s2,m,n-1),editDist(s1,s2,m-1,n),editDist(s1,s2,m-1,n-1));
    }
}

int main(){
    char s1[1002],s2[1002];
    scanf("%s%s",s1,s2);
    printf("%d",editDist(s1,s2,strlen(s1),strlen(s2)));
    return 0;
}
