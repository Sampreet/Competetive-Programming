int climbStairs(int n) {
    if(n==0||n==1){
        return 1;
    }
    int a=1,b=1,i;
    for(i=2;i<=n;i++){
        a=a+b;
        b=a-b;
    }
    return a;
}
