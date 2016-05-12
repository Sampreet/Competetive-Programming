#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}

int main() {
    int count[26]={0};
    char str[100002];
    int i,j=0,cnt=0,cnt1=0,cnt2=0;
    scanf("%s",str);
    for(i=0;str[i];i++){
        count[str[i]-'a']++;
    }
    for(i=0;i<26;i++){
        j=max(j,count[i]);
    }
    int mark=0;
    j=j-1;
    for(i=0;i<26;i++){
        if(count[i]!=0){
            cnt1++;
            if(count[i]!=j){
                cnt++;
                if(cnt>1){
                    mark=1;
                }
                if(count[i]==j+1){
                    cnt2++;
                }
            }
        }
    }
    if(cnt1==cnt2){
        mark=0;
    }
    cnt=0;
    if(cnt1=cnt2+1){
        for(i=0;i<26;i++){
            if(count[i]==1){
                cnt++;
            }
        }
        if(cnt==1){
            mark=0;
        }
    }
    if(mark==0){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
