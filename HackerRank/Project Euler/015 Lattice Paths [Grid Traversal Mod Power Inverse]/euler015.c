#include<stdio.h>
#define MOD 1000000007

long long power(int a, int b)
{
    long long ans=1,y=a;
    while(b>0)
    {
        if(b%2==1){
            ans=(ans*y)%MOD;
        }
        y=(y*y)%MOD;
        b/=2;
    }
    return ans;
}

int main(){
    long long t,m,i,n,temp,*f;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&m,&n);
        if(m<n){
            temp=m;
            m=n;
            n=temp;
        }
        f=(long long*)malloc((m+n+1)*sizeof(long long));
        f[1]=1;
        for (i=2;i<=m+n;i++)
            f[i]= (f[i-1]*i) % MOD;
        printf("%lld\n",(f[n+m]*((power(f[n],MOD-2) * power(f[m],MOD-2)) % MOD) )% MOD);
        free(f);

    }
    return 0;
}
