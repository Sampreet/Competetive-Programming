int Solution::findMin(const vector<int> &A) {
    int low=0,high=A.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[low]<=A[high]){
            return A[low];
        }
        int next=(mid+1)%A.size();
        int prev=(mid+A.size()-1)%A.size();
        if(A[mid]<=A[prev] && A[mid]<=A[next]){
            return A[mid];
        }
        else if(A[mid]<=A[high]){
            high=mid-1;
        }
        else if(A[mid]>=A[low]){
            low=mid+1;
        }
    }
    return -1;
}
