bool comp(string a,string b){
    return a+b>b+a;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> str;
    for(int i=0;i<A.size();i++){
        str.push_back(to_string(A[i]));
    }
    sort(str.begin(),str.end(),comp);
    string res="";
    for(int i=0;i<str.size();i++){
        res=res+str[i];
    }
    int i=0;
    while(res[i]=='0' && i+1<res.size())
        i++;
    return res.substr(i);
}
