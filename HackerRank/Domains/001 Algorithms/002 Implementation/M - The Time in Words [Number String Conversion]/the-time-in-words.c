#include<stdio.h>

int main(){
    int h,m,modeC=0;
    char zeroTo19[20][10]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char oneTo12[13][10]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","one"};
    char tens[10][10]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    char mode[2][10]={"past","to"};
    scanf("%d%d",&h,&m);
    if(m==0){
        printf("%s o' clock",oneTo12[h-1]);
    }
    if(m==30){
        printf("half past %s",oneTo12[h-1]);
        m=0;
    }
    else{
        while(m>0){
            if(m>0&&m<30){
                if(m==15){
                    printf("quarter %s %s",mode[modeC],oneTo12[h-1+modeC]);
                    m=0;
                }
                else{
                    if(m%10==0){
                        printf("%s minutes %s %s",tens[m/10],mode[modeC],oneTo12[h-1+modeC]);
                        m=0;
                    }
                    if(m>20){
                        printf("twenty %s minutes %s %s",zeroTo19[m-20],mode[modeC],oneTo12[h-1+modeC]);
                        m=0;
                    }
                    else{
                        if(m==1){
                            printf("one minute %s %s",mode[modeC],oneTo12[h-1+modeC]);
                            m=0;
                        }
                        else
                            printf("%s minutes %s %s",zeroTo19[m],mode[modeC],oneTo12[h-1+modeC]);
                            m=0;
                    }
                }
            }
            else{
                m=60-m;
                modeC=1;
            }
        }
    }
    return 0;
}
