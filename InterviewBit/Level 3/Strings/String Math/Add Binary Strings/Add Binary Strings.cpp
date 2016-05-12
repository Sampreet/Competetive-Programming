string Solution::addBinary(string A, string B) {
    string res;
    int len1=A.size();
    int len2=B.size();
    int len=max(len1,len2);
    int carry=0;
    if(len1<len2){
        for(int i=0;i<len2-len1;i++){
            A='0'+A;
        }
    }
    if(len1>len2){
        for(int i=0;i<len1-len2;i++){
            B='0'+B;
        }
    }
    for(int i=len-1;i>=0;i--){
        int first=A[i]-'0';
        int second=B[i]-'0';
        int sum=(first^second^carry)+'0';
        res=(char)sum+res;
        carry=(first&second)|(second&carry)|(first&carry);
    }
    if(carry){
        res='1'+res;
    }
    return res;
}
