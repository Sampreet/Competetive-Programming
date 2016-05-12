#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i=0,j,*ret,n,d[10002],c[26]={0},ct,w[26],want[26],have[26],p,l;
    char s[10002];
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++){
        d[i]=s[n-i-1]-'a';
        c[d[i]]++;
    }
    for(i=0;i<26;i++)
        w[i]=c[i]/2;
    ret=(int*)malloc((n/2)*sizeof(int));
    for(i=0;2*i<n;i++){
        for(ct=0;ct<26;ct++){
            ret[i]=ct;
            p=0;
            l=0;
            for(j=0;j<n;j++){
                if(ret[p]==d[j]){
                    p++;
                    l=j;
                    if(p>i)
                        break;
                }
            }
            if(p>i){
                for(j=0;j<26;j++){
                    want[j]=w[j];
                    have[j]=0;
                }
                for(j=0;j<=i;j++)
                    want[ret[j]]--;
                for(j=l+1;j<n;j++)
                    have[d[j]]++;
                int ok=1;
                for(j=0;j<26;j++)
                    if(want[j]<0 || want[j]>have[j])
                        ok=0;
                if(ok)
                    break;
            }
        }
    }
    for(i=0;i<n/2;i++)
        printf("%c",(char)(ret[i]+'a'));
    free(ret);
    return 0;
}
