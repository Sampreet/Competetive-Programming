int strStr(const char* txt, const char* pat) {
    int M=strlen(pat);
    int N=strlen(txt);
    int i,j;

    if(M==0 || N==0){
        return -1;
    }

    int *lps=(int*)malloc(M*sizeof(int));
    int len=0;

    lps[0]=0;
    i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }

    i=0;
    j=0;
    while(i<N){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }

        if(j==M)
        {
            return i-j;
            j=lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
    free(lps);
    return -1;
}
