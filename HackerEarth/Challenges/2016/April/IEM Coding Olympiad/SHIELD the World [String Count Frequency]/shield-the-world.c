#include<string.h>
#include<stdio.h>

int main(){
    int t,n,cnt[26],i;
    char s[404];
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        for(n=0;n<26;n++){
            cnt[n]=0;
        }
        n=strlen(s);
        for(i=0;i<n;i++){
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a']>s[i]-'a'+1){
                printf("S.H.I.E.L.D\n");
                n=-1;
                break;
            }
        }
        if(n!=-1){
            for(i=0;i<26;i++){
                if(cnt[i]!=0 && cnt[i]!=i+1){
                    printf("S.H.I.E.L.D\n");
                    n=-1;
                    break;
                }
            }
        }
        if(n!=-1){
            printf("HYDRA\n");
        }
    }
    return 0;
}
