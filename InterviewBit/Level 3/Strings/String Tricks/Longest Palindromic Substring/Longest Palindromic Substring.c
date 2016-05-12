char* longestPalindrome(char* A){
    int maxLength=1;
    int start=0;
    int len=strlen(A);
    int low, high, i;
    for(i=1;i<len;++i){
        low=i-1;
        high=i;
        while(low>=0 && high<len && A[low]==A[high]){
            if (high-low+1>maxLength){
                start=low;
                maxLength=high-low+1;
            }
            --low;
            ++high;
        }
        low=i-1;
        high=i+1;
        while(low>=0 && high<len && A[low]==A[high]){
            if (high-low+1>maxLength){
                start=low;
                maxLength=high-low+1;
            }
            --low;
            ++high;
        }
    }
    char* res=(char*)malloc((maxLength+1)*sizeof(char));
    for(i=0;i<maxLength;i++){
        res[i]=A[start+i];
    }
    res[maxLength]='\0';
    return res;
}
