#include<stdio.h>

int main()
{
    int a[6]={},i;
    char t;
    scanf("%d:%d:%d%c%*c",&a[0],&a[2],&a[4],&t);
    if(a[0]==12)
    {
        if(t=='A')
            a[0]=0;
        if(t=='P')
            a[0]=12;
    }
    else
    {
        if(t=='P')
            a[0]+=12;
    }
    for(i=0;i<6;i+=2)
    {
        a[i+1]=a[i]%10;
        a[i]/=10;
    }
    printf("%d%d:%d%d:%d%d",a[0],a[1],a[2],a[3],a[4],a[5]);
    return 0;
}

