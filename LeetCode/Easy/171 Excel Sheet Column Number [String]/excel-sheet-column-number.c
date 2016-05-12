int titleToNumber(char* s) {
    int res=0;
    for(int i=0;s[i];i++){
        s[i]-='A';
        res=res*26+(int)s[i]+1;
    }
    return res;
}
