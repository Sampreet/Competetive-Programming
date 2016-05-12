#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char ch[102],temp;
    int i,j,cnt=0,t,mark,l;
    scanf("%d",&t);
    while(t--)
    {
        mark=0;
        scanf("%s",ch);
        l=strlen(ch);
        mark=0;
        i=l-1;
        while(i>0 && ch[i-1]>=ch[i])
            i--;
        if(i<=0)
            mark=1;
        else
        {
            j=l-1;
            while(ch[j]<=ch[i-1])
                j--;
            temp=ch[i-1];
            ch[i-1]=ch[j];
            ch[j]=temp;
            j=l-1;
            while(i<j) {
                temp=ch[i];
                ch[i]=ch[j];
                ch[j]=temp;
                i++;
                j--;
            }
        }
        if(mark==0)
            printf("%s\n",ch);
        else
            printf("no answer\n");
    }
    return 0;
}
