#include<stdio.h>
#include<stdlib.h>

int abs(int a){
    return a>0?a:-a;
}
int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

int main(){
	int t,x[2],y[2];
	char ch;
	scanf("%c%d\n",&ch,&y[0]);
	x[0]=ch-'a'+1;
	scanf("%c%d",&ch,&y[1]);
	x[1]=ch-'a'+1-x[0];
	y[1]-=y[0];
	printf("%d\n",max(abs(x[1]),abs(y[1])));
	if(x[1]>=0 && y[1]>=0){
		for(t=0;t<min(x[1],y[1]);t++){
			printf("RU\n");
		}
		if(y[1]>x[1]){
			y[1]-=x[1];
			for(t=0;t<y[1];t++){
				printf("U\n");
			}
		}
		else{
			x[1]-=y[1];
			for(t=0;t<x[1];t++){
				printf("R\n");
			}
		}
		return 0;
	}
	else if(x[1]>=0 && y[1]<=0){
		y[1]=-y[1];
		for(t=0;t<min(x[1],y[1]);t++){
			printf("RD\n");
		}
		if(y[1]>x[1]){
			y[1]-=x[1];
			for(t=0;t<y[1];t++){
				printf("D\n");
			}
		}
		else{
			x[1]-=y[1];
			for(t=0;t<x[1];t++){
				printf("R\n");
			}
		}
		return 0;
	}
	else if(x[1]<=0 && y[1]<=0){
		y[1]=-y[1];
		x[1]=-x[1];
		for(t=0;t<min(x[1],y[1]);t++){
			printf("LD\n");
		}
		if(y[1]>x[1]){
			y[1]-=x[1];
			for(t=0;t<y[1];t++){
				printf("D\n");
			}
		}
		else{
			x[1]-=y[1];
			for(t=0;t<x[1];t++){
				printf("L\n");
			}
		}
		return 0;
	}
	else{
		x[1]=-x[1];
		for(t=0;t<min(x[1],y[1]);t++){
			printf("LU\n");
		}
		if(y[1]>x[1]){
			y[1]-=x[1];
			for(t=0;t<y[1];t++){
				printf("U\n");
			}
		}
		else{
			x[1]-=y[1];
			for(t=0;t<x[1];t++){
				printf("L\n");
			}
		}
		return 0;
	}
	return 0;
}
