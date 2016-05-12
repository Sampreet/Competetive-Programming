#include<stdio.h>

int main()
{
    int t,i,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        sum=1;
        while(i>0){
            sum=2*sum;
            i--;
            if(i>0){
                sum=sum+1;
                i--;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
