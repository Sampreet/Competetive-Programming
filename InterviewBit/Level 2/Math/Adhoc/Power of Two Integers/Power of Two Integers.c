int isPower(int A) {
    int MAX=2147483647;
    if(A<=1){
        return 1;
    }
    int base;
    for(base=2;base<A && base<MAX/base;base++){
        int temp=base;
        while(temp<A && temp<MAX/base){
            temp*=base;
        }
        if(temp==A){
            return 1;
        }
    }
    return 0;
}
