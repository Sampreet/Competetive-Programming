#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(){
	int d,i,j,max_t=0,min_t=0,sum,*ma,*mi;
	scanf("%d%d",&d,&sum);
	ma=(int*)malloc(d*sizeof(int));
	mi=(int*)malloc(d*sizeof(int));
	for(i=0;i<d;i++){
		scanf("%d%d",&mi[i],&ma[i]);
		max_t+=ma[i];
		min_t+=mi[i];
	}
	if(min_t>sum || max_t<sum){
		printf("NO\n");
		return 0;
	}
	else{
		printf("YES\n");
		sum-=min_t;
		i=0;
		while(sum!=0){
			j=min(sum,ma[i]-mi[i]);
			mi[i]+=j;
			sum-=j;
			i++;
		}
		for(i=0;i<d;i++){
			printf("%d ",mi[i]);
		}
	}
	return 0;
}