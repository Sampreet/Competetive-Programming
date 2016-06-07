#include<stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    int t,N,i,R,G,B,maxi;
    char str[100002];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        scanf("%s",str);
        i=0;maxi=0;
        R=0;B=0;G=0;
        while(str[i]){
            switch(str[i]){
                case 'R':
                    R++;
                    break;
                case 'B':
                    B++;
                    break;
                default:
                    G++;
            }
            i++;
        }
        maxi=max(max(R,G),B);
        printf("%d\n",N-maxi);
    }
    return 0;
}
