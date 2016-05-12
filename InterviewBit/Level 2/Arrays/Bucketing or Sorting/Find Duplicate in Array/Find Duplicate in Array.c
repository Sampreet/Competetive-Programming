int repeatedNumber(const int* A, int n) {
    int i;
	int sq=sqrt(n);
	int range=n/sq;
	int arr[range+1];
	int blockno=range;
	for(i=0;i<range+1;i++)
		arr[i]=0;
	for(i=0;i<n;i++)
		arr[A[i]/sq]+=1;
	i=1;
	while(i<range && arr[i]<=sq) i++;
	if(i<range)
	    blockno=i;
	if(arr[0]==sq)
		blockno=0;
	for(i=0;i<sq;i++)
		arr[i]=0;
	for(i=0;i<n;i++){
		if(A[i]>=blockno*sq && A[i]<(blockno+1)*sq){
			arr[A[i]-blockno*sq]+=1;
			if(arr[A[i]-blockno*sq]>1)
				return A[i];
		}

	}
	return -1;
}
