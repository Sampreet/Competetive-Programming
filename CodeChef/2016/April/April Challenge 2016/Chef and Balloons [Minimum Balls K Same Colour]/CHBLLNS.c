#include<stdio.h>

long long min(int a,int b){
    return a<b?(long long)a:(long long)b;
}

int main(){
    int t,a,b,c,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&k);
        printf("%lld\n",min(a,k-1)+min(b,k-1)+min(c,k-1)+1);
    }
    return 0;
}
