#include<stdio.h>

int main()
{
    int N,i,a,p=0,n=0,z=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&a);
        if(a==0)
            z++;
        if(a>0)
            p++;
        if(a<0)
            n++;
    }
    printf("%0.3f\n%0.3f\n%0.3f\n",(float)p/((float)N),(float)n/((float)N),(float)z/((float)N));
    return 0;
}
