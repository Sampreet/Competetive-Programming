#include<stdio.h>
#include<math.h>

long long rev(long long k)
{
    long long l=0;
    while(k>0)
    {
        l*=10;
        l+=k%10;
        k/=10;
    }
    return l;
}

int main()
{
    long long N,i,p,f;
    int t,mark=1;
    scanf("%d",&t);
    while(t--){
        mark=0;
        scanf("%lld",&N);
        while(N>=100000){
            if(rev(N)!=N)
                N--;
            else{
                p=sqrt(N);
                for(i=101;i<=p;i++){
                    if(N%i==0 && (N/i/1000==0)){
                        mark=1;
                        break;
                    }
                }
                if(mark==1){
                    printf("%lld\n", N);
                    break;
                }
                else
                    N--;
            }
        }

    }
    return 0;
}

