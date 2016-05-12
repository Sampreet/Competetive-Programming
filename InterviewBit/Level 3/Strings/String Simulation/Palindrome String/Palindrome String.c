int isAN(char ch){
    if((ch>=65 && ch<=90)||(ch>=48 && ch<=57)||(ch>=97 && ch<=122))
        return 1;
    return 0;
}

int isNum(char ch){
    if(ch>=48 && ch<=57){
        return 1;
    }
    return 0;
}

int areEqual(char ch1, char ch2){
    if(isAN(ch1) & isAN(ch2)){
        if((isNum(ch1)&isNum(ch2)) && (ch1==ch2)){
            return 1;
        }
        else if((!isNum(ch1)&!isNum(ch2)) && ((ch1==ch2)||(abs(ch1-ch2)==32))){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

int isPalindrome(char* A){
    int i=0,j=strlen(A)-1;
    while(i<=j){
        if(!isAN(A[i])){
            i++;
        }
        else if(!isAN(A[j])){
            j--;
        }
        else if(areEqual(A[i],A[j])){
            j--;
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}
