#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int p[100005];

bool mycmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first>b.first;
}

int main(){
    int t,n,m,i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int> > w;
        for(i=0;i<n;i++){
            cin>>p[i];
        }
        for(i=0;i<n;i++){
            cin>>m;
            w.push_back(pair<int,int> (p[i],m));
        }
        sort(w.begin(),w.end(),mycmp);
        m=0;
        for(i=1;i<n;i++){
            if(w[i].second<w[i-1].second){
                cout<<"NO"<<endl;
                m=1;
                break;
            }
        }
        if(m==0)
            cout<<"YES"<<endl;
    }
    return 0;
}
