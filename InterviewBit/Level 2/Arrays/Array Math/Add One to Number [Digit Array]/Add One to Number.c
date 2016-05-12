int* plusOne(int* A, int n1, int *length_of_array) {
    int start,len,i=0;
    while(A[i]==0){
        i++;
        if(i==n1)
            break;
    }
    if(i==n1){
        *length_of_array=1;
        int *result=(int*)malloc(sizeof(int));
        result[0]=1;
        return result;
    }
    start=i;
    len=n1-start+1;
    int *result=(int*)malloc(len*sizeof(int));
    int carry=1;
    for(i=0;i<len;i++){
        result[len-i-1]=(i==len-1)?0:A[n1-1-i];
        result[len-i-1]+=carry;
        carry=result[len-i-1]/10;
        result[len-i-1]%=10;
    }
    if(result[0]==0){
        *length_of_array=len-1;
        return &result[1];
    }
    *length_of_array=len;
    return result;
}
