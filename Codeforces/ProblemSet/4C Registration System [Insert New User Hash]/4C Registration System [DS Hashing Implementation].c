#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HM 1007

struct dict{
	char name[34];
	int reqID;
};

struct table{
	struct dict *D;
	int entry;
};

int hash(char *name){
	int res=0,i=0;
	while(name[i]){
		res=(res*13+name[i]-'a')%HM;
		i++;
	}
	return res%HM;
}

void insert(char *name, struct table *U){
	int h=hash(name);
	int i;
	for(i=0;i<U[h].entry;i++){
		if(strcmp(name,U[h].D[i].name)==0){
			U[h].D[i].reqID++;
			printf("%s%d\n",U[h].D[i].name,U[h].D[i].reqID);
			return;
		}
	}
	i++;
	if(i==1){
		U[h].D=(struct dict*)malloc(i*sizeof(struct dict));
	}
	U[h].D=realloc(U[h].D,i*sizeof(struct dict));
	U[h].D[i-1].reqID=0;
	strcpy(U[h].D[i-1].name,name);
	U[h].entry++;
	printf("OK\n");
	return;
}

int main(){
	int N,i,j;
	char str[34];
	struct table users[HM];
	for(i=0;i<HM;i++){
		users[i].entry=0;
	}
	scanf("%d",&N);
	while(N--){
		scanf("%s",str);
		insert(str,users);
	}
	return 0;
}
