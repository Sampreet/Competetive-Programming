#define MOD 1000003
#define MAX_CHAR 256
int findRank (char* str){
    int len = strlen(str);
    int mul[len+1];
    int rank = 1,i,j;
    int count[MAX_CHAR] = {0};
    mul[0]=1;
    long long ans;
    for(i=1;i<=len;i++){
        ans=((mul[i-1]%MOD)*(i%MOD));
        ans%=MOD;
        mul[i]=(int)ans;
    }
    for(i=0;str[i];++i)
        ++count[str[i]];
    for(i=1;i<256;++i)
        count[i]+=count[i-1];

    for(i=0;i<len;++i){
        ans=((count[str[i]-1])*(mul[len-i-1]%MOD));
        ans%=MOD;
        rank=(rank+(int)ans)%MOD;

        for(j=str[i];j<MAX_CHAR;++j)
            --count[j];
    }
    return rank%MOD;
}
