#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<long long,long long> > s;
vector<long long> a,b;
vector<long long> c;

bool mycmp(pair<long long,long long> a,pair<long long,long long> b){
    return (a.first/a.second)<(b.first/b.second);
}

int main(){
	long long n,k,i,j,mini=100000;
	pair<long long,long long> temp;
	pair<long long,long long> t;
	cin>>n>>k;
	for(i=0;i<n;i++){
        cin>>j;
        a.push_back(j);
	}
	for(i=0;i<n;i++){
        cin>>j;
        b.push_back(j);
        mini=min(mini,b[i]/a[i]);
	}
	long long cnt=mini;
	for(i=0;i<n;i++){
        temp.first=b[i]-a[i]*mini;
        temp.second=a[i];
        s.push_back(temp);
	}
	sort(s.begin(),s.end(),mycmp);
	long long p=0,l=k;
	while(k>0){
        i=0;
        k=l;
        while(k>=0 && i<n && (s[i].first/s[i].second)<=p){
            k-=s[i].second*(p+1)-s[i].first;
            i++;
        }
        p++;
        if(k>=0)
            cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
