int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<3){
        return 1000000000;
    }
    sort(A.begin(),A.end());
    int mini=INT_MAX;
    for(int i=0;i<A.size()-2;i++){
        int j=i+1,k=A.size()-1;
        while(j<k){
            int diff=A[i]+A[j]+A[k]-B;
            if(abs(diff)<abs(mini)){
                mini=diff;
            }
            if(diff==0){
                return B;
            }
            else if(diff<0){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return B+mini;
}
