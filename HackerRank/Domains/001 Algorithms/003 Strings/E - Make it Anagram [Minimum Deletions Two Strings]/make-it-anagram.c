#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch[2][10002];
    int arr[2][26]={},i,j,cnt=0;
    scanf("%s",ch[0]);
    scanf("%s",ch[1]);
    for(i=0;i<2;i++)
    {
        for(j=0;ch[i][j];j++)
        {
            arr[i][ch[i][j]-'a']++;
        }
    }
    cnt=0;
    for(i=0;i<26;i++)
    {
        if(arr[1][i]!=arr[0][i])
            cnt+=abs(arr[1][i]-arr[0][i]);
    }
    printf("%d",cnt);
    return 0;
}
