#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    long i,j,t,r,c,flag,trans;
    char in[20],ch,co[5];
    scanf("%ld",&t);
    for(i=0;i<t;i++){
        scanf("%s",&in);
        ch=in[0];
        flag=0;
        if(ch=='R' && in[1]<58){
            for(j=2;j<9;j++){
                if(in[j]=='C'){
                    flag=1;
                    break;
                }
            }
        }
        trans=0;
        j=0;
        r=0;
        c=0;
        while(ch!='\0'){
            if(flag==0){
                if(ch>64)
                    co[j]=ch;
                else{
                    r=r*10+ch-48;
                    co[j]='\0';
                }
            }
            else if(flag==1 && trans==0){
                if(ch=='C')
                    trans=1;
                else if(ch<64)
                    r=r*10+ch-48;
            }
            else if(flag==1 && trans==1){
                if(ch<64)
                    c=c*10+ch-48;
            }
            j++;
            ch=in[j];
        }

        if(flag==0){
            c=0;
            for(j=0;j<sizeof(co);j++){
                if(co[j]>64){
                    c=c*26 + co[j]-64;
                }
                else
                    break;
            }
            printf("R%dC%d\n", r,c);
        }

        if(flag==1){
            j=0;
            while(c!=0){
                if(c%26!=0){
                    co[j]=c%26+64;
                    c=c/26;
                }
                else{
                    co[j]=c%26+90;
                    c=c/26-1;
                }
                j++;
            }
            co[j]=0;
            printf("%s%d\n", strrev(co),r);
        }

        memset(co,0,sizeof(co));
        memset(in,0,sizeof(in));
    }
    return 0;
}
