#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char ch[10002];
    int arr[26]={},i,cnt=0,t,len;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<26;i++)
            arr[i]=0;
        scanf("%s",ch);
        len=strlen(ch);
        if(len%2==0)
        {
            for(i=0;i<len/2;i++)
            {
                arr[ch[i]-'a']++;
            }
            for(i=len/2;i<len;i++)
            {
                arr[ch[i]-'a']--;
            }
            cnt=0;
            for(i=0;i<26;i++)
            {
                if(arr[i]!=0)
                    cnt+=abs(arr[i]);
            }
            printf("%d\n",cnt/2);
        }
        else
            printf("-1\n");
    }
    return 0;
}
