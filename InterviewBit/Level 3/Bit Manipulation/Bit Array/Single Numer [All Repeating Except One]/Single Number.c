int singleNumber(const int* A, int n1) {
    int xor1=0,i;
    for(i=0;i<n1;i++){
        xor1^=A[i];
    }
    return xor1;
}
