int cntBits(int* A, int n1) {
    long long mod=1000000007;
    long long res=0,count;
    int i,j;
    for(i=0;i<32;i++){
        count=0;
        for(j=0;j<n1;j++){
            if(A[j]&(1<<i)){
                count++;
            }
        }
        res=(res+((count*(n1-count)*2)%mod))%mod;
    }
    return (int)res;
}
