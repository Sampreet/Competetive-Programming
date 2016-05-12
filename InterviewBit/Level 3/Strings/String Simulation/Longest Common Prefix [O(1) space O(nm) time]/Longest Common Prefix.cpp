string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.size()==0){
        return "";
    }
    if(A.size()==1){
        return A[0];
    }
    for(int i=0;i<A[0].size();i++){
        for(int j=0;j<A.size()-1;j++){
            if(i>=A[j].size() || A[j][i]!=A[j+1][i]){
                return A[j].substr(0,i);
            }
        }
    }
    return A[0];
}
