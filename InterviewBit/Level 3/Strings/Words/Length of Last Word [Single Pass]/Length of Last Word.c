int lengthOfLastWord(const char* A) {
    if(A[0]=='\0'){
        return 0;
    }
    int i=0,j,prevj=-1;
    if(A[0]!=' '){
        prevj=0;
    }
    for(j=1;A[j];j++){
        if(A[j]==' ' && A[j-1]!=' '){
            prevj=j-1;
        }
        if(A[j-1]==' ' && A[j]!=' '){
            i=j;
        }
        if(A[j+1]=='\0' && A[j]!=' '){
            prevj=j;
        }
    }
    return prevj-i+1;
}
