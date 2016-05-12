#include<stdio.h>

int main()
{
    char ch[102];
    int arr[26]={},i,j,cnt,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",ch);
        for(j=0;ch[j];j++)
        {
            if(arr[ch[j]-'a']==i)
                arr[ch[j]-'a']++;
        }
    }
    cnt=0;
    for(i=0;i<26;i++)
    {
        if(arr[i]==t)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
