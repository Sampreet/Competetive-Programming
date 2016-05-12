#include<stdio.h>
#include<string.h>

int table[5003][5003];

int max(int a,int b){
    return a>b?a:b;
}

int maxCommonChild(char *str1,char *str2,int len1,int len2){
    int i,j;
    for(i=0;i<=len1;i++){
        table[i][0]=0;
    }
    for(j=0;j<=len2;j++){
        table[0][j]=0;
    }
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1]){
                table[i][j]=max(max(table[i][j-1], table[i-1][j]),table[i-1][j-1]+1);
            }
            else{
                table[i][j]=max(max(table[i][j-1], table[i-1][j]),table[i-1][j-1]);
            }
        }
    }
    return (table[len1][len2]);
}

int main(){
    char str1[5002],str2[5002];
    scanf("%s%s",str1,str2);
    printf("%d",maxCommonChild(str1,str2,strlen(str1),strlen(str2)));
    return 0;
}
