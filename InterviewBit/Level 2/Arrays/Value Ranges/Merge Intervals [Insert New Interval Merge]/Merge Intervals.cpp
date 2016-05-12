bool mycomp(Interval a, Interval b){
    return a.start > b.start;
}

vector<Interval> merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), mycomp);
    int index = 0;
    for (int i=0; i<A.size(); i++){
        if (index != 0 && A[index-1].start <= A[i].end){
            while (index != 0 && A[index-1].start <= A[i].end){
                A[index-1].end = max(A[index-1].end, A[i].end);
                A[index-1].start = min(A[index-1].start, A[i].start);
                index--;
            }
        }
        else
            A[index] = A[i];
        index++;
    }
    vector<Interval> B;
    while(index>0){
        B.push_back(A[--index]);
    }
    return B;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
}
