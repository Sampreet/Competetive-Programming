#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 26

int isAnagram(int *count1,int *count2){
    int i;
    for(i=0;i<SIZE;i++){
        if(count1[i]!=count2[i])
            return 0;
    }
    return 1;
}

int findPair(char *str,int start,char *sub,int n,int sublen,int len){
    int count1[SIZE]={0},count2[SIZE]={0},cnt=0,i,j;
    if(sublen>len-start){
        return 0;
    }
    for(i=0;i<n&&(start+i)<len;i++){
        count1[sub[i]-'a']++;
        count2[str[start+i]-'a']++;
    }
    for(j=start+i;j<len; j++) {
        if(isAnagram(count1,count2)){
            cnt++;
        }
        count2[str[start]-'a']--;
        count2[str[j]-'a']++;
        start++;
    }
    if(j==len){
        if(isAnagram(count1,count2)){
            cnt++;
        }
    }
    return cnt;
}

int countPairs(char *str) {
    int n=strlen(str),cnt=0,i,j,k;
    char *tmp;
    if(n<2){
        return 0;
    }
    tmp=malloc(n*sizeof(char));
    for(i=0;i<n;i++){
        k=0;
        for(j=i;j<n;j++){
            tmp[k]=str[j];
            tmp[k+1]='\0';
            cnt+=findPair(str,i+1,tmp,k+1,strlen(tmp),n);
            k++;
        }
    }
    free(tmp);
    return cnt;
}

int main()
{
    char ch[102];
    int cnt,t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",ch);
        printf("%d\n",countPairs(ch));
    }
    return 0;
}
