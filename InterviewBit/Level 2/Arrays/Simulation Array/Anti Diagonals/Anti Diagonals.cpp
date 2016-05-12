vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > res;
    int i,j,k;
    for(j=0;j<A.size();j++){
        k=j;
        vector<int> temp;
        for(i=0;i<=j;i++){
            temp.push_back(A[i][k]);
            k--;
        }
        res.push_back(temp);
    }
    for(i=1;i<A.size();i++){
        k=i;
        vector<int> temp;
        for(j=A.size()-1;j>=i;j--){
            temp.push_back(A[k][j]);
            k++;
        }
        res.push_back(temp);
    }
    return res;
}
