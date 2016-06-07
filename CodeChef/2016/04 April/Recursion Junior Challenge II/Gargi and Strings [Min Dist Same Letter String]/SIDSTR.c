#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 2147483647

long long min(long long a,long long b){
    return a<b?a:b;
}

long long abso(long long a){
    return a>0?a:-a;
}

int main(){
    int t,n,m,i,j,k,cnt[26];
    long long sum,mini;
    char s[100005];
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        n=strlen(s);
        if(n==1){
            printf("0\n");
            continue;
        }
        for(i=0;i<26;i++){
            cnt[i]=0;
        }
        for(i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        mini=INT_MAX;
        for(i=0;i<26;i++){
            sum=0;
            for(j=0;j<26;j++){
                sum+=cnt[j]*(j-i);
            }
            mini=min(abso(sum),mini);
        }
        printf("%lld\n",mini);
    }
    return 0;
}
