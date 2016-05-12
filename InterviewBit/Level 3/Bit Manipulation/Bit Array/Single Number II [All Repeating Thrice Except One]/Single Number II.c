int singleNumber(const int* A, int n1) {
    int res=0;
    int sum,i,j,x;
    for(i=0;i<32;i++){
        sum=0;
        x=(1<<i);
        for(j=0;j<n1;j++){
            if(x&A[j]){
                sum++;
            }
        }
        if(sum%3){
            res|=x;
        }
    }
    return res;
}
