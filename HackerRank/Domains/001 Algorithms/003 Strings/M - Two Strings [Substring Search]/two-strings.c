#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch[2][100002];
    int arr[2][26]={},i,j,cnt=0,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<2;i++)
        {
            for(j=0;j<26;j++)
                arr[i][j]=0;
        }
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
            if(arr[0][i]>0 && arr[1][i]>0)
            {
                cnt=1;
                printf("YES\n");
                break;
            }
        }
        if(cnt==0)
            printf("NO\n");
    }
    return 0;
}
