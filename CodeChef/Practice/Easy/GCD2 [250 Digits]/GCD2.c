#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    char s[256];
    int a,temp,i,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&a,s);
        if(a==0){
            printf("%s\n",s);
        }
        else{
            i=0;
            temp=0;
            while(s[i]){
                temp*=10;
                temp+=s[i]-'0';
                temp%=a;
                i++;
            }
            printf("%d\n",gcd(a,temp));
        }
    }
    return 0;
}
