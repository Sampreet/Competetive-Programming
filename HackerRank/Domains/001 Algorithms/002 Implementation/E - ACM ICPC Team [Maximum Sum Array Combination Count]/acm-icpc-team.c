#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,n,i,j,k,teamCount=0,maximumN=0,sum;
    char **matrix,ch;
    scanf("%d%d",&t,&n);
    matrix=(char**)malloc(t*sizeof(char*));
    ch=getchar();
    for(i=0;i<t;i++){
        while(ch=='\n'){
            ch=getchar();
        }
        matrix[i]=(char*)malloc(n*sizeof(char));
        for(j=0;j<n;j++){
            matrix[i][j]=ch-'0';
            ch=getchar();
        }
        for(k=i-1;k>=0;k--){
            sum=0;
            for(j=0;j<n;j++){
                sum+=((matrix[i][j]==1)&&(matrix[k][j]==1))?1:matrix[i][j]+matrix[k][j];
            }
            if(sum>maximumN){
                teamCount=1;
                maximumN=sum;
            }
            else
                if(sum==maximumN)
                    teamCount++;
        }
    }
    printf("%d\n%d",maximumN,teamCount);
    free(matrix);
    return 0;
}
