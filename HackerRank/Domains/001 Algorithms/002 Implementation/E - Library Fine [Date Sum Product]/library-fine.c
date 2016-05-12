#include<stdio.h>

int main()
{
    int a[6]={},h=0;
    char t;
    scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
    if(a[2]>a[5])
        h=10000;
    else
    {
        if(a[1]>a[4] && a[2]==a[5])
            h=(a[1]-a[4])*500;
        else
        {
            if(a[0]>a[3] && a[2]==a[5] && a[1]==a[4])
                h=(a[0]-a[3])*15;
        }
    }
    printf("%d",h);
    return 0;
}

