#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int t,n,m,i,j,k,cnt[26];
    char s[100005];
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        for(i=0;i<26;i++){
            cnt[i]=0;
        }
        n=strlen(s);
        for(i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        i=0;
        while(s[i]){
            if(cnt[s[i]-'a']==1){
                break;
            }
            i++;
        }
        j=n-1;
        while(j>=0){
            if(cnt[s[j]-'a']==1){
                break;
            }
            j--;
        }
        if(i<n){
            if(s[i]>s[j]){
                printf("SHANKY\n");
            }
            else if(s[i]<s[j]){
                printf("ANKU\n");
            }
            else{
                printf("PANDEY\n");
            }
        }
        else{
            printf("PANDEY\n");
        }
    }
    return 0;
}
