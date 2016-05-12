bool isHappy(int n) {
    while(n!=89 && n!=1){
        int temp=0;
        while(n>0){
            temp+=(n%10)*(n%10);
            n/=10;
        }
        n=temp;
    }
    if(n==89){
        return false;
    }
    return true;
}
