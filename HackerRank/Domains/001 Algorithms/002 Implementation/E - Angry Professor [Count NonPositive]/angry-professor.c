#include<stdio.h>

int main()
{
    int t,N,K,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&K);
        cnt=K;
        while(N--)
        {
            scanf("%d",&K);
            if(K<=0)
                cnt--;
        }
        if(cnt<=0)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
