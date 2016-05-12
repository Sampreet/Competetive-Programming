#include<stdio.h>

int main(){
    long long N,t,i,j;
    char temp;
    long long fact[14]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&N);
        if(N==fact[13]){
            printf("mlkjihgfedcba\n");
        }
        else{
            N--;
            char ch[]="abcdefghijklm",ch2[15];
            j=0;
            while(j<13){
                i=N/fact[13-j-1];
                N%=fact[13-j-1];
                ch2[j]=ch[i];
                for(i=i;ch[i];i++){
                    ch[i]=ch[i+1];
                }
                j++;
            }
            ch2[j]='\0';
            printf("%s\n",ch2);
        }
    }
    return 0;
}
