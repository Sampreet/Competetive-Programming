vector<int> Solution::allFactors(int A) {
    vector<int> res;
    int root=(int)(sqrt(A));
    for(int i=1;i<root;i++){
        if(A%i==0){
            res.push_back(i);
            res.push_back(A/i);
        }
    }
    if(root*root==A){
        res.push_back(root);
    }
    else if(A%root==0){
        res.push_back(root);
        res.push_back(A/root);
    }
    sort(res.begin(),res.end());
    return res;
}
