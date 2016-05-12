int Solution::divide(int dividend, int divisor) {
    if(!divisor){
        return INT_MAX;
    }
    if(dividend==INT_MIN && divisor==-1){
        return INT_MAX;
    }
    long long dvd=abs((long long)dividend);
    long long dvs=abs((long long)divisor);

    int i=0;
    while((dvs<<(i+1))<=dvd){
        i++;
    }

    int res=0;
    while(dvd>=dvs){
        if(dvd>=(dvs<<i)){
            dvd-=dvs<<i;
            res+=1<<i;
        }
        i--;
    }
    if((divisor>0&&dividend>0)||(divisor<0&&dividend<0)){
        return res;
    }
    return 0-res;
}
