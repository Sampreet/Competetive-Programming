#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long count2(long long a){
	long long res=0;
	while(a%2==0 && a!=0){
		res++;
		a/=2;
	}
	return res;
}

long long count5(long long a){
	long long res=0;
	while(a%5==0 && a!=0){
		res++;
		a/=5;
	}
	return res;
}

long long min(long long a, long long b){
	return a<b?a:b;
}

void calculatePath(long long **mat, int n, int mark, int x, int y){
	long long dp[n][n][2];
	char path[n][n][2],res[n+n+2];
	int i,j,k;
	i=0;
	dp[0][i][0]=count2(mat[0][i]);
	dp[0][i][1]=count5(mat[0][i]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==0 && i==0)
				continue;
			else if(j==0){
				dp[i][0][0]=dp[i-1][0][0]+count2(mat[i][0]);
				dp[i][0][1]=dp[i-1][0][1]+count5(mat[i][0]);
				path[i][0][0]='D';
				path[i][0][1]='D';
			}
			else if(i==0){
				dp[0][j][0]=dp[0][j-1][0]+count2(mat[0][j]);
				dp[0][j][1]=dp[0][j-1][1]+count5(mat[0][j]);
				path[0][j][0]='R';
				path[0][j][1]='R';
			}
			else{
                dp[i][j][0]=(dp[i][j-1][0]>=dp[i-1][j][0]?dp[i-1][j][0]:dp[i][j-1][0]);
                path[i][j][0]=(dp[i][j-1][0]>=dp[i-1][j][0]?'D':'R');
                dp[i][j][0]+=count2(mat[i][j]);
                dp[i][j][1]=(dp[i][j-1][1]>=dp[i-1][j][1]?dp[i-1][j][1]:dp[i][j-1][1]);
                path[i][j][1]=(dp[i][j-1][1]>=dp[i-1][j][1]?'D':'R');
                dp[i][j][1]+=count5(mat[i][j]);
			}
		}
	}
	if(mark && min(dp[n-1][n-1][0],dp[n-1][n-1][1])>0){
        printf("1\n");
        for(k=0;k<x;k++){
            printf("D");
        }
        for(k=0;k<y;k++){
            printf("R");
        }
        for(k=0;k<n-y-1;k++){
            printf("R");
        }
        for(k=0;k<n-x-1;k++){
            printf("D");
        }
	}
	else{
        printf("%lld\n",min(dp[n-1][n-1][0],dp[n-1][n-1][1]));
        int p=0;
        if(dp[n-1][n-1][0]>dp[n-1][n-1][1]){
            p=1;
        }
        i=n-1;
        j=n-1;
        k=0;
        while(i!=0 && j!=0){
            res[k]=path[i][j][p];
            k++;
            if(path[i][j][p]=='D'){
                i--;
            }
            else{
                j--;
            }
        }
        while(i!=0){
            res[k]='D';
            k++;
            i--;
        }
        while(j!=0){
            res[k]='R';
            k++;
            j--;
        }
        res[k]='\0';
        printf("%s\n",strrev(res));
    }
}

int main(){
	int n,mark=0,x,y;
	long long **mat;
	scanf("%d",&n);
	mat=(long long**)malloc(n*sizeof(long long *));
	int i,j;
	for(i=0;i<n;i++){
		mat[i]=(long long*)malloc(n*sizeof(long long));
		for(j=0;j<n;j++){
			scanf("%lld",&mat[i][j]);
			if(mat[i][j]==0){
                mat[i][j]=10;
                mark=1;
                x=i;
                y=j;
			}
		}
	}
	calculatePath(mat,n,mark,x,y);
	free(mat);
	return 0;
}
