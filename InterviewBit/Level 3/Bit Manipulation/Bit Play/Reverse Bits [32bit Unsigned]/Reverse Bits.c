unsigned int reverse(unsigned int A) {
    unsigned int res=0;
    int i;
    for(i=0;i<32;i++){
        if(A&(1<<i)){
            res|=1<<(31-i);
        }
    }
    return res;
}
