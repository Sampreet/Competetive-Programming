#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long maxSum(const vector<long long> &A,long long M) {
    vector<long long> P(A.size());
    set<long long> S;
    long long res=0,i,a;
    for(i=0;i<A.size();++i)
        P[i]=(A[i]+(i>0?P[i-1]:0))%M;
    for(i=A.size()-1;i>=0;--i){
        S.insert(P[i]);
        a=(A[i]-P[i]+M)%M;
        auto it=S.lower_bound(M-a);
        if(it!=begin(S))
            res=max(res,*prev(it)+a);
        res=max(res,(*prev(end(S))+a)%M);
    }
    return res;
}


int main(){
    long long i,j,N,t,mod,sum=0;
    cin>>t;
    while(t--){
        cin>>N>>mod;
        vector<long long> A(N);
        for(i=0;i<N;i++){
            cin>>A[i];
            A[i]%=mod;
        }
        printf("%lld\n",maxSum(A,mod));
    }
    return 0;
}
