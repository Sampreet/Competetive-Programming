#include<stdio.h>
typedef int bool;
#define true 1
#define false 0

int check(int c, int a, int b, int x)
{
    if(c-b*x<0)
        return -1;
    if((c-b*x)%a!=0)
        return (check(c,a,b,x+1));
    return x;
}
int main()
{
    int N,t,p,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        p=check(N,3,5,0);
        if(p!=-1)
        {
            for(i=5*p;i<N;i++)
                printf("5");
            for(i=0;i<5*p;i++)
                printf("3");
            printf("\n");
        }
        else
            printf("-1\n");

    }
    return 0;
}
