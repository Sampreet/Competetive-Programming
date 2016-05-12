int Solution::removeDuplicates(vector<int> &A) {
    int i=A.size();
    if(i==0 || i==1){
        return i;
    }
    i=1;
    for(int j=1;j<A.size();j++){
        if(A[j-1]!=A[j]){
            A[i]=A[j];
            i++;
        }
    }
    return i;
}
