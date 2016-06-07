#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,N,*l,*r,ind,max_here,max_r,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		l=(int*)malloc(N*sizeof(int));
		r=(int*)malloc(N*sizeof(int));
		for(i=0;i<N;i++){
            scanf("%d",&l[i]);
		}
		for(i=0;i<N;i++){
            scanf("%d",&r[i]);
		}
		max_here=0;
		max_r=0;
		for(i=1;i<=N;i++){
			if(l[i-1]*r[i-1]>max_here){
				max_here=l[i-1]*r[i-1];
				max_r=r[i-1];
				ind=i;
			}
			else if(l[i-1]*r[i-1]==max_here){
				if(r[i-1]>max_r){
					max_r=r[i-1];
					ind=i;
				}
			}
		}
		free(l);
		free(r);
		printf("%d\n",ind);
	}
	return 0;
}
