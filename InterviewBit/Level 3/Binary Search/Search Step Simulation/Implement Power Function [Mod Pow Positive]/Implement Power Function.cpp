int Solution::pow(int x, int n, int d) {
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1%d;
    }
    long long p=x;
    long long res=1;
    while(n>0){
        if(n%2==1){
            res=(res*p)%d;
        }
        p=(p*p)%d;
        n/=2;
    }
    return res<0?(res+d)%d:res;
}
