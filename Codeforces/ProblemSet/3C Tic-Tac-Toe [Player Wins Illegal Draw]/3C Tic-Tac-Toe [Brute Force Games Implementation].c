#include<stdio.h>
#include<stdlib.h>

int checkVert(char **mat,char a,int col){
	int j;
	for(j=0;j<3;j++){
		if(mat[j][col]!=a){
			return 0;
		}
	}
	return 1;
}

int checkHor(char **mat,char a,int row){
	int j;
	for(j=0;j<3;j++){
		if(mat[row][j]!=a){
			return 0;
		}
	}
	return 1;
}

int checkWin(char **mat){
	int xwin=0,owin=0;
	int i;
	for(i=0;i<3;i++){
		if(checkHor(mat,'X',i) || checkVert(mat,'X',i)){
			xwin=1;
		}
		if(checkHor(mat,'0',i) || checkVert(mat,'0',i)){
			owin=1;
		}
	}
	if((mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X') || (mat[0][2]=='X' && mat[1][1]=='X' && mat[2][0]=='X')){
		xwin=1;
	}
	if((mat[0][0]=='0' && mat[1][1]=='0' && mat[2][2]=='0') || (mat[0][2]=='0' && mat[1][1]=='0' && mat[2][0]=='0')){
		owin=1;
	}
	if(xwin==1 && owin==1){
		return 3;
	}
	if(xwin==1){
		return 1;
	}
	if(owin==1){
		return 2;
	}
	return 0;
}

int main(){
	int t=0,i,j,k,tx=0,to=0,tot;
	char **mat;
	mat=(char**)malloc(3*sizeof(char*));
	for(i=0;i<3;i++){
        mat[i]=(char*)malloc(3*sizeof(char));
		scanf("%c%c%c%*c",&mat[i][0],&mat[i][1],&mat[i][2]);
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(mat[i][j]=='0'){
				t++;
				to++;
			}
			else if(mat[i][j]=='X'){
				t++;
				tx++;
			}
		}
	}
	int mark=checkWin(mat);
	if(mark==3 || (to!=tx && to!=tx-1)){
		printf("illegal\n");
		return 0;
	}
	if(mark==0){
		if(tx==5){
			printf("draw\n");
		}
		else if(tx==to){
			printf("first\n");
		}
		else{
			printf("second\n");
		}
	}
	else if(mark==1){
	    if(to==tx){
            printf("illegal\n");
            return 0;
	    }
		printf("the first player won\n");
	}
	else{
        if(to!=tx){
            printf("illegal\n");
            return 0;
	    }
		printf("the second player won\n");
	}
	return 0;
}
