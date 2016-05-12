#include<stdio.h>

int main(){
    int N,a,b,c,t,maxi,i,den,num;
    scanf("%d",&t);
    while(t--){
        maxi=0;
        scanf("%d",&N);
        for(b=1;b<N/2+N%2;b++){
            num=N*(N-2*b);
            den=2*(N-b);
            if(num%den==0){
                a=num/den;
                c=N-a-b;
                if(a*b*c>maxi){
                    maxi=a*b*c;
                }
            }
        }
        if(maxi==0)
            printf("-1\n");
        else
            printf("%d\n",maxi);
    }
}
