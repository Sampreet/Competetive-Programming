vector<string> Solution::prettyJSON(string A) {
    vector<string> res;
    if(A.length()==0){
        return res;
    }
    string indent="";
    string temp="";
    int i=0,len=A.length();
    while(i<len){
        temp.push_back(A[i]);
        switch(A[i]){
            case',':
                res.push_back(temp);
                temp=indent;
                i++;
                break;
            case ':':
                i++;
                if(A[i]=='{' || A[i]=='['){
                    res.push_back(temp);
                    temp=indent;
                }
                break;
            case ' ':
                i++;
                break;
            case '{':
            case '[':
                i++;
                res.push_back(temp);
                if(i<len && (A[i]!='}' || A[i]!=']')){
                    indent.push_back('\t');
                }
                temp=indent;
                break;
            case '}':
            case ']':
                i++;
                if(i<len && (A[i]==',')){
                    break;
                }
                res.push_back(temp);
                if(i<len && (A[i]=='}' || A[i]==']')){
                    if(!indent.empty()){
                        indent.pop_back();
                    }
                }
                temp=indent;
                break;
            default:
                i++;
                if(i<len && (A[i]=='}' || A[i]==']')){
                    res.push_back(temp);
                    if(!indent.empty()){
                        indent.pop_back();
                    }
                    temp=indent;
                }
        }
    }
    return res;
}
