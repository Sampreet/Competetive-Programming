#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t,i,mark,N;
    char S[10002];
    scanf("%d",&t);
    while(t--)
    {
        mark=0;
        scanf("%s",S);
        N=strlen(S);
        for(i=1;i<N;i++)
        {
            if(abs((int)S[i]-(int)S[i-1])!=abs((int)S[N-i-1]-(int)S[N-i]))
            {
                mark=1;
                break;
            }
        }
        if(mark==0)
            printf("Funny\n");
        else
            printf("Not Funny\n");
    }
    return 0;
}
