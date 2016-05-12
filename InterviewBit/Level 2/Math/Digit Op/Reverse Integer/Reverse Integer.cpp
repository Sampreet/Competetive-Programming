int Solution::reverse(int A) {
    int mark=1;
    long B=A,res=0;
    if(A<0){
        mark=-1;
        B*=-1;
    }
    else{
        B=A;
    }
    while(B>0){
        res*=10;
        res+=B%10;
        B/=10;
    }
    res*=mark;
    if(res>2147483647 || res<-2147483648){
        return 0;
    }
    else{
        return (int)res;
    }
}
