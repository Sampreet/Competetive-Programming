int ** generateMatrix(int A, int *number_of_rows, int *number_of_columns) {
    int n=A;
	*number_of_rows = n;
	*number_of_columns = n;
	int **result=(int**)malloc(n*sizeof(int*));
	int i,k=0,l=0,p=1,m=n;
	for(i=0;i<n;i++){
        result[i]=(int*)malloc(n*sizeof(int));
	}
    while(k<m&&l<n){
        for(i=l;i<n;++i){
            result[k][i]=p++;
        }
        k++;
        for(i=k;i<m;++i){
            result[i][n-1]=p++;
        }
        n--;
        if(k<m){
            for(i=n-1;i>=l;--i){
                result[m-1][i]=p++;
            }
            m--;
        }
        if(l<n){
            for(i=m-1;i>=k;--i){
                result[i][l]=p++;
            }
            l++;
        }
    }
	return result;
}
