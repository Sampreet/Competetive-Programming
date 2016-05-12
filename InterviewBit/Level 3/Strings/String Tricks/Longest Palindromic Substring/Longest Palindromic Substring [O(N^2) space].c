int longContPalinSubStr(char *str,int n){
    int table[n][n],max_len,i,j,k,start;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            table[i][j]=0;
        }
    }
    max_len=1;
    for(i=0;i<n;i++)
        table[i][i]=1;
    start=0;
    for(i=0;i<n;i++){
        if(str[i]==str[i+1]){
            table[i][i+1]=1;
            start=i;
            max_len=2;
        }
    }
    for(k=3;k<=n;k++){
        for(i=0;i<n-k+1;i++){
            j=i+k-1;
            if(table[i+1][j-1] && str[i]==str[j]){
                table[i][j]=1;
                if(k>max_len){
                    start=i;
                    max_len=k;
                }
            }
        }
    }
    return max_len;
}
