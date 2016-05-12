string Solution::convert(string A, int B) {
    if(B==1){
        return A;
    }
    int len=A.length();
    string res[B];
    int row=0;
    bool down=true;
    for(int i=0;i<len;i++){
        res[row].push_back(A[i]);
        if(row==B-1){
            down=false;
        }
        else if(row==0){
            down=true;
        }
        down?(row++):(row--);
    }
    A="";
    for(int i=0;i<B;i++){
        A+=res[i];
    }
    return A;
}
