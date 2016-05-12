int titleToNumber(char* A) {
    int res=0,i=0;
    for(i=0;A[i];i++){
        A[i]-='A';
        res=res*26+(int)A[i]+1;
    }
    return res;
}
