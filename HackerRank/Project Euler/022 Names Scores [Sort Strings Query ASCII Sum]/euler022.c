#include<stdio.h>
#include<string.h>

int main(){
    int N,Q,i,j,sum;
    char **str,ch,temp[14];
    scanf("%d",&N);
    str=(char**)malloc(N*sizeof(char*));
    for(i=0;i<N;i++){
        str[i]=(char*)malloc(14*sizeof(char));
        scanf("%s",str[i]);
    }
    for(i=0;i<N;i++){
        for(j=0;j<N-1;j++){
            if(strcmp(str[j],str[j+1])>0){
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%s",temp);
        sum=0;
        for(i=0;i<N;i++){
            if(strcmp(str[i],temp)==0){
                for(j=0;j<strlen(str[i]);j++){
                    sum+=str[i][j]-'A'+1;
                }
                sum*=(i+1);
                break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
