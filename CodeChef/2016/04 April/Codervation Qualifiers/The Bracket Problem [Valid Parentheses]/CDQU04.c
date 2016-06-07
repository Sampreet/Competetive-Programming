#include<stdio.h>

void isValid(char* s) {
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
                    printf("no\n");
                    return;
                }
                else{
                    j--;
                }
            }
            i++;
        }
    if(j==0)
        printf("yes\n");
    else
        printf("no\n");
}

int main(){
    int t;
    char str[102];
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        isValid(str);
    }
    return 0;
}
