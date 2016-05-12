#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
    long long T,N,i,h,t,countS;
    char name[22][12];
    char zeroToNineteen[20][10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    char tens[10][10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    char thousandPower[5][10]={"Hundred","Thousand","Million","Billion","Trillion"};
    scanf("%lld",&T);
    while(T--){
        i=0;
        countS=0;
        scanf("%lld",&N);
        if(N==0){
            printf("ZERO");
        }
        else
        while(N>0){
            h=N%1000;
            N=N/1000;
            if(i>0 && h>0){
                strcpy(name[countS],thousandPower[i]);
                countS++;
                //printf("%s ",thousandPower[i]);
            }
            t=h%100;
            h=h/100;
            if(t>=20){
                //printf("%s %s ",tens[t/10],zeroToNineteen[t%10]);
                if(t%10==0){
                    strcpy(name[countS],tens[t/10]);
                    countS++;
                }
                else{
                    strcpy(name[countS],zeroToNineteen[t%10]);
                    countS++;
                    strcpy(name[countS],tens[t/10]);
                    countS++;
                }
            }
            else if(t<20 && t>0){
                //printf("%s ",zeroToNineteen[t]);
                strcpy(name[countS],zeroToNineteen[t]);
                countS++;
            }
            if(h>0){
                //printf("%s HUNDRED ",zeroToNineteen[h]);
                strcpy(name[countS],thousandPower[0]);
                countS++;
                strcpy(name[countS],zeroToNineteen[h]);
                countS++;
            }
            ++i;
        }
        for(i=countS-1;i>=0;i--){
            printf("%s ",name[i]);
        }
        printf("\n");
    }
    return 0;
}
