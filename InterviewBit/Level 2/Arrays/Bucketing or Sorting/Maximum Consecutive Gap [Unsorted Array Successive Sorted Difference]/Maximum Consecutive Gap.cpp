int min(int a, int b){
    return a<b?a:b;
}

int max(int a, int b){
    return a>b?a:b;
}

int findMin(vector<int> num){
    int m=INT_MAX;
    for(int i=0;i<num.size();i++){
        m=min(m,num[i]);
    }
    return m;
}

int findMax(vector<int> num){
    int m=INT_MIN;
    for(int i=0;i<num.size();i++){
        m=max(m,num[i]);
    }
    return m;
}

int Solution::maximumGap(const vector<int> &A) {

    if(A.size()<2){
        return 0;
    }
    if(A.size()==2){
        return max(A[0],A[1])-min(A[0],A[1]);
    }
    int num_min=findMin(A);
    int num_max=findMax(A);
    int len=(num_max-num_min)/(A.size()-1)+1;

    vector<pair<int, int>> buckets (A.size(),pair<int,int>(INT_MAX, INT_MIN));

    for(int i=0;i<A.size();i++){
        int index=(A[i]-num_min)/len;
        buckets[index].first=min(buckets[index].first,A[i]);
        buckets[index].second=max(buckets[index].second,A[i]);
    }

    int gap=0;
    int prev=buckets[0].second;
    for(int i=1;i<buckets.size();i++) {
        if(prev!=INT_MIN && buckets[i].first!=INT_MAX){
            gap=max(gap,buckets[i].first-prev);
            prev=buckets[i].second;
        }
    }
    return gap;
}
