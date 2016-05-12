int addDigits(int num) {
    if(num==0){
        num=0;
    }
    else if(num%9==0){
        num=9;
    }
    else{
        num%=9;
    }
    return num;
}
