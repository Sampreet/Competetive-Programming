#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int neg(int a){
    return a>0?0:a;
}

int minSubStr(char* s, int a, int t, int g, int c, int n){
    int curr_min,min=n,i,j,at=0,gt=0,ct=0,tt=0,ap=0,tp=0,gp=0,cp=0;
    a=neg(a);t=neg(t);g=neg(g);c=neg(c);
    if(a+t+g+c==0){
        return 0;
    }
    i=0;
    j=i;
    while(j<n){
        switch(s[j]){
            case 'A':
                at++;
                break;
            case 'G':
                gt++;
                break;
            case 'T':
                tt++;
                break;
            default:
                ct++;
        }
        while(neg(at-ap+a)+neg(tt-tp+t)+neg(gt-gp+g)+neg(ct-cp+c)==0 && i<=j){
            if(min>j+1-i)
                min=j+1-i;
            switch(s[i]){
                case 'A':
                    ap++;
                    break;
                case 'G':
                    gp++;
                    break;
                case 'T':
                    tp++;
                    break;
                default:
                    cp++;
            }
            i++;
        }
        j++;
    }
    return min;
}

int main() {
    int n,A,T,G,C,i;
    scanf("%d",&n);
    A=n/4;T=n/4;G=n/4;C=n/4;
    char* s=(char*)malloc((n+2)*sizeof(char));
    scanf("%s",s);
    for(i=0;s[i];i++){
        switch(s[i]){
            case 'A':
                A--;
                break;
            case 'G':
                G--;
                break;
            case 'T':
                T--;
                break;
            default:
                C--;
        }
    }
    printf("%d",minSubStr(s,A,T,G,C,n));
    free(s);
    return 0;
}
