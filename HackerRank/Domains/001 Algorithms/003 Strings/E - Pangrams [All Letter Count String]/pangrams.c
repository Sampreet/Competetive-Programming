#include<stdio.h>

int main()
{
    char ch;
    int arr[26]={},i,mark=0;
    ch=getchar();
    while(ch!=EOF)
    {
        if((int)ch>64 && (int)ch<91)
            arr[ch-'A']++;
        if((int)ch>96 && (int)ch<123)
            arr[ch-'a']++;
        ch=getchar();
    }
    for(i=0;i<26;i++)
    {
        if(arr[i]==0)
        {
            printf("not pangram\n");
            mark=1;
            break;
        }
    }
    if(mark==0)
        printf("pangram\n");
    return 0;
}
