int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far=A[0],i,curr_max=A[0],n=A.size();
    for(i=1;i<n;i++){
        curr_max=max(A[i],curr_max+A[i]);
        max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far;
}
