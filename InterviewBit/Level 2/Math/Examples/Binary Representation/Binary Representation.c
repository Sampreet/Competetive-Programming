char* findDigitsInBinary(int A) {
	int i,n;
	char *temp=(char*)malloc(101*sizeof(char));
	if(A==0){
	    char *result=(char*)malloc(2*sizeof(char));
	    result[0]='0';
	    result[1]='\0';
	    return result;
	}
	i=0;
	while(A>0){
	    temp[i]=A%2+'0';
	    A/=2;
	    i++;
	}
	n=i;
	char *result=(char*)malloc(101*sizeof(char));
	for(i=0;i<n;i++){
	    result[i]=temp[n-i-1];
	}
	result[n]='\0';
	return result;
}
