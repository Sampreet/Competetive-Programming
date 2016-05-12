#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,i,j,in;
    char **A;
    scanf("%d%*c",&N);
    A=(char **)malloc(N*sizeof(char *));
    for(i=0;i<N;i++)
    {
        A[i]=(char *)malloc(N*sizeof(char));
        for(j=0;j<N;j++)
        {
            scanf("%c",&A[i][j]);
        }
        scanf("%*c");
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i>0 && i<N-1 && j>0 && j<N-1)
            {
                if(A[i][j]>A[i-1][j] && A[i][j]>A[i][j-1] && A[i][j]>A[i][j+1] && A[i][j]>A[i+1][j])
                    printf("X");
                else
                    printf("%c",A[i][j]);
            }
            else
                printf("%c",A[i][j]);
        }
        printf("\n");
    }
    free(A);
    return 0;
}
