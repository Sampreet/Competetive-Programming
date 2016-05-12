bool Solution::hotel(vector<int> &arr, vector<int> &dep, int K) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int curr=1,mini=1;
    int i=1,j=0,n=arr.size();
    while(i<n && j<n){
        if(arr[i]<dep[j]){
            curr++;
            i++;
            if(curr>mini){
                mini=curr;
            }
        }
        else{
            curr--;
            j++;
        }
    }
    return mini>K?false:true;
}

}
