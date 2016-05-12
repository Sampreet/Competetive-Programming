string delSpaces(const string &s){
    int i=0;
    while (s[i]==' '){
        i++;
    }
    int j=s.size()-1;
    while (s[j]==' '){
        j--;
    }
    string res="";
    for (int k=i;k<=j;k++){
        res = res+s[k];
    }
    return res;
}

bool valid(string &s){
    int i=0;
    bool e=false;
    bool dot=false;
    bool dig=false;

    while(i<s.size()-1){
        if(i==0){
            if(s[i]<'0' || s[i]>'9'){
                if (s[i]=='+' || s[i]=='-' || s[i]=='.'){
                    if(s.size()==1){
                        return false;
                    }
                    if(s[i]=='.'){
                        dot=true;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                dig=true;
            }
            i++;
            continue;
        }
        if(i>0){
            switch (s[i]){
                case 'e':
                    if(e==false && s[i-1]!='+' && s[i-1]!='-' && dig && i!=s.size()-1 && s[i-1]!='.') {
                        e=true;
                    }
                    else{
                        return false;
                    }
                    break;
                case '+':
                    if(s[i-1]!='e'){
                        return false;
                    }
                    break;
                case '-':
                    if(s[i-1]!='e'){
                        return false;
                    }
                    break;
                case '.':
                    if(dot==false && e==false){
                        dot=true;
                    }
                    else{
                        return false;
                    }
                    break;
                default:
                    if(s[i]<'0'||s[i]>'9'){
                        return false;
                    }
                    else{
                        dig=true;
                    }
                    break;
            }
            i++;
            continue;
        }
    }
    if(s[s.size()-1]>='0' && s[s.size()-1]<='9'){
        return true;
    }
    return false;
}

int Solution::isNumber(const string &A) {
    string str=delSpaces(A);
    if(str.size()==0){
        return 0;
    }
    return valid(str)?1:0;
}
