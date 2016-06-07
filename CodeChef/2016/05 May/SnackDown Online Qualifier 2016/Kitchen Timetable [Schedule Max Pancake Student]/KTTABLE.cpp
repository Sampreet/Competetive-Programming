#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n, in, i, j, b, cnt, t;
    cin>>t;
    while(t--){
        cnt=0;
        cin>>n;
        vector<int> a;
        cin>>in;
        b=in;
        a.push_back(in);
        for(i=1;i<n;i++){
            cin>>in;
            a.push_back(in-b);
            b=in;
        }
        for(i=0;i<n;i++){
            cin>>in;
            if(in<=a[i]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
