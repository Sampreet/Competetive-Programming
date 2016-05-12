#include<stdio.h>

int main()
{
    char ch;
    int arr[26]={},i,mark=0,cnt;
    ch=getchar();
    while(ch!=EOF)
    {
        arr[ch-'a']++;
        ch=getchar();
    }
    cnt=0;
    for(i=0;i<26;i++)
    {
        if(arr[i]%2==1)
        {
            cnt++;
        }
        if(cnt>1)
        {
            printf("NO\n");
            mark=1;
            break;
        }
    }
    if(mark==0)
        printf("YES\n");
    return 0;
}
