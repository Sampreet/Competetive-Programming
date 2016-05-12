#include<stdio.h>

int main()
{
    char A[100002],a;
    int t,cnt,i;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%s",A);
        a=A[0];
        for(i=1;A[i];i++)
        {
            if(A[i]==a)
                cnt++;
            a=A[i];
        }
        printf("%d\n",cnt);
    }
}
