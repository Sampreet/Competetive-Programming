int* repeatedNumber(const int* A, int n1, int *length_of_array) {
    *length_of_array = 2;
    int *result = (int *) malloc(*length_of_array * sizeof(int));
    int xor1;
    int set_bit_no;
    int i;
    int x = 0;
    int y = 0;
    xor1 = A[0];
    for(i=1;i<n1;i++)
        xor1=xor1^A[i];
    for(i=1;i<=n1;i++)
        xor1=xor1^i;
    set_bit_no=xor1&~(xor1-1);
    for(i=0;i<n1;i++){
        if(A[i] & set_bit_no)
            x=x^A[i];
        else
            y=y^A[i];
    }
    for(i=1;i<=n1;i++){
        if(i & set_bit_no)
            x=x^i;
        else
            y=y^i;
    }
    for(i=0;i<n1;i++){
        if(A[i]==x){
            result[0]=x;
            result[1]=y;
            return result;
        }
    }
    result[0]=y;
    result[1]=x;
    return result;
}
