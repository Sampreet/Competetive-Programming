int uniquePaths(int A, int B) {
    if(A<1 && B<1){
        return 0;
    }
    int i;
    long long sum=1;
    for(i=A;i<A+B-1;i++){
        sum*=i;
        sum/=i-A+1;
    }
    return (int) sum;
}
