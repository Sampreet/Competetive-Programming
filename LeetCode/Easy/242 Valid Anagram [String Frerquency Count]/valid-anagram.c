bool isAnagram(char* s, char* t) {
    int *count1;
    count1=(int*)malloc(256*sizeof(int));
    for(int i=0;i<256;i++){
        count1[i]=0;
    }
    for(int i=0;s[i];i++){
        count1[s[i]]++;
    }
    for(int i=0;t[i];i++){
        count1[t[i]]--;
        if(count1[t[i]]<0){
            free(count1);
            return false;
        }
    }
    for(int i=0;i<256;i++){
        if(count1[i]!=0){
            free(count1);
            return false;
        }
    }
    free(count1);
    return true;
}
