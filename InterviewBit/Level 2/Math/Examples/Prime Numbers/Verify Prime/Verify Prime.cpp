int Solution::isPrime(int A) {
    int i,root=sqrt(A);
    if(A==1)
        return 0;
    if(A%2==0)
        return 0;
    else{
        for(i=3;i<=root;i+=2){
            if(A%i==0 && A!=i)
                return 0;
        }
        return 1;
    }
}
