int* flip(char* A, int *len1) {
    int *result;
    int i,n1=0,mark=0;
    while(A[n1]!='\0'){
        if(A[n1]=='0')
            mark=1;
        n1++;
    }
    if(n1==0 || mark==0){
        *len1=0;
        result=(int*)malloc(0*sizeof(int));
        return result;
    }
    int sum=0,maxsum=0,num=0;
	int startIndex=0,stopIndex=0,prevIndex=0;
	for(i=0;i<n1;i++){
		if(A[i] == '1'){
			num = -1;
		}else if(A[i] == '0'){
			num = 1;
		}
		sum = sum + num;
		if(maxsum<sum){
			maxsum = sum;
			prevIndex = startIndex;
			stopIndex = i;
		}else if(sum<0){
			sum = 0;
			startIndex = i+1;
	    }
	}
    result=(int*)malloc(2*sizeof(int));
    *len1=2;
    result[0]=prevIndex+1;
    result[1]=stopIndex+1;
    return result;
}
