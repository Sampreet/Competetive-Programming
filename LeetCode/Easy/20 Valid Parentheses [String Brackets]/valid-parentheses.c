bool isValid(char* s) {
    char* arr=(char*)malloc(sizeof(char));
    int i,j=0;
    i=0;
    while(s[i]!=NULL){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                arr=realloc(arr,(j+1)*sizeof(char));
                arr[j]=s[i];
                j++;
            }
            else {
                if(((s[i]==')' && arr[j-1]!='(')) || ((s[i]=='}' && arr[j-1]!='{')) || ((s[i]==']' && arr[j-1]!='['))){
                    return false;
                }
                else{
                    j--;
                }
            }
            i++;
        }
    if(j==0)
        return true;
    else
        return false;
}