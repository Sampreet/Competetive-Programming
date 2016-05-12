int Solution::maxArea(vector<int> &A) {
    if(A.size()<2){
        return 0;
    }
    int area=0,a_now=0;
    int i=0,j=A.size()-1;
    while(i<j){
        a_now=(j-i)*min(A[i],A[j]);
        if(a_now>area){
            area=a_now;
        }
        if(A[i]<=A[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return area;
}
