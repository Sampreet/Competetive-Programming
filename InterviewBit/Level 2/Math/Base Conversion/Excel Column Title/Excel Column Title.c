char* convertToTitle(int A) {
	char str[50];
    int i = 0;
    while (A>0){
        int rem = A%26;
        if (rem==0){
            str[i++] = 'Z';
            A = (A/26)-1;
        }
        else{
            str[i++] = (rem-1) + 'A';
            A = A/26;
        }
    }
    str[i] = '\0';
    int len=i;
    char *res=(char*)malloc((len+1)*sizeof(char));
    for(i=0;i<len;i++){
        res[i]=str[len-i-1];
    }
    res[len]='\0';
    return res;
}
