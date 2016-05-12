#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,K;
    char *str;
    scanf("%d",&N);
    str=(char *)malloc((N+2)*sizeof(char));
    scanf("%s",str);
    scanf("%d",&K);
    for(N=0;str[N];N++)
    {
        if(str[N]>64 && str[N]<91)
        {
            printf("%c",'A'+((str[N]-'A')+K)%26);
        }
        else if(str[N]>96 && str[N]<123)
        {
            printf("%c",'a'+((str[N]-'a')+K)%26);
        }
        else
            printf("%c",str[N]);
    }
    free(str);
    return 0;
}
