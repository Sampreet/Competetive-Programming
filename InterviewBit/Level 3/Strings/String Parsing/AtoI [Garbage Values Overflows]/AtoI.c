int isDigit(char a){
    return (a>='0' && a<='9')?1:0;
}

int matoi(const char *A){
    long long value=0;
    int sign=1;
    while(*A==' '){
        A++;
    }
    if(*A=='+'){
        A++;
    }
    if(*A=='-'){
        sign=-1;
        A++;
    }
    while(isDigit(*A)){
        value*=10;
        value+=(long long)(*A-'0');
        A++;
        if(sign*value>INT_MAX){
            value=sign*INT_MAX;
            break;
        }
        if(sign*value<INT_MIN){
            value=sign*INT_MIN;
            break;
        }
    }
    return (int)(sign*value);
}
