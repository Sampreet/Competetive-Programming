vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> res;
    int l=0,k=0;
    for(int i=0;i<A.size();i+=k){
        for(k=l=0;i+k<A.size() && l+A[i+k].size()<=B-k;k++){
            l+=A[i+k].size();
        }
        string temp=A[i];
        for(int j=0;j<k-1;j++){
            if(i+k>=A.size()){
                temp+=" ";
            }
            else{
                temp+=string((B-l)/(k-1)+(j<(B-l)%(k-1)),' ');
            }
            temp+=A[i+j+1];
        }
        temp+=string(B-temp.size(),' ');
        res.push_back(temp);
    }
    return res;
}
