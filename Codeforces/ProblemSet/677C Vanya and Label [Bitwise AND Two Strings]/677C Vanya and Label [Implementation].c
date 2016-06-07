#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MOD 1000000007

int main(){
    int n,i,j,k,cnt,temp;
    long long ans=1;
    char s[100005];
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        cnt=0;
        if(s[i]>='0' && s[i]<='9'){
            temp=s[i]-'0';
        }
        else if(s[i]>='A' && s[i]<='Z'){
            temp=s[i]-'A'+10;
        }
        else if(s[i]>='a' && s[i]<='z'){
            temp=s[i]-'a'+36;
        }
        else if(s[i]=='-'){
            temp=62;
        }
        else{
            temp=63;
        }
        while(temp>0){
            if(temp%2==1){
                cnt++;
            }
            temp/=2;
        }
        temp=1;
        cnt=6-cnt;
        if(cnt!=0){
            while(cnt>0){
                temp*=3;
                cnt--;
            }
        }
        ans=(ans*((long long)temp))%MOD;
    }
    printf("%d",(int)ans);
    return 0;
}
