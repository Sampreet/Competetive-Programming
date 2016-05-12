#include<stdio.h>
#include<string.h>

int main(){
    int t,i,j,x,y,len1,len2,k;
    char A[100002],B[100002],C[200005];
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",A,B);
        i=0;
        j=0;
        k=0;
        len1=strlen(A);
        len2=strlen(B);
        while(i<len1 && j<len2){
            if(A[i]<B[j]){
                C[k]=A[i];
                k++;
                i++;
            }
            else if(A[i]>B[j]){
                C[k]=B[j];
                k++;
                j++;
            }
            else{
                x=i;
                y=j;
                char a=A[i];
                for(;x<len1&&y<len2;x++,y++){
                    if(A[x]!=B[y]){
                        break;
                    }
                    else if(A[x]>a){
                        for(;i<x;i++){
                            C[k]=A[i];
                            k++;
                        }
                        for(;j<y;j++){
                            C[k]=B[j];
                            k++;
                        }
                        i=x;
                        j=y;
                        a=A[x];
                    }
                }
                if(x==len1){
                    C[k]=B[j];
                    k++;
                    j++;
                }
                else if(y==len2){
                    C[k]=A[i];
                    k++;
                    i++;
                }
                else{
                    if(A[x]<B[y]){
                        C[k]=A[i];
                        k++;
                        i++;
                    }
                    else{
                        C[k]=B[j];
                        k++;
                        j++;
                    }
                }
            }
        }
        for(;i<len1;i++){
            C[k]=A[i];
            k++;
        }
        for(;j<len2;j++){
            C[k]=B[j];
            k++;
        }
        C[k]='\0';
        printf("%s\n",C);
    }
    return 0;
}
