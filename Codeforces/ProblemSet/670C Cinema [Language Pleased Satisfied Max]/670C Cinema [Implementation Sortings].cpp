#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<pair<int,int>,int> > arr;
vector<int> s,a,b;
vector<pair<int,int> > c;

bool mycmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first==b.first.first){
        return a.first.second>b.first.second;
    }
    return a.first.first>b.first.first;
}

int bS(int low,int high,int x){
    if(high>=low){
        int mid=low+(high-low)/2;
        if(x==c[mid].first)
            return mid;
        if(x>c[mid].first)
            return bS((mid+1),high,x);
        else
            return bS(low,(mid-1),x);
    }
    return -1;
}

int main(){
	int n,k,i,j;
	pair<pair<int,int>,int> temp;
	pair<int,int> t;
	cin>>n;
	for(i=0;i<n;i++){
        cin>>j;
        s.push_back(j);
	}
	sort(s.begin(),s.end());
	t.first=s[0];
	t.second=1;
	i=1;
	while(i<n){
        if(s[i]==s[i-1]){
            t.second++;
        }
        else{
            c.push_back(t);
            t.first=s[i];
            t.second=1;
        }
        i++;
	}
	c.push_back(t);
	int p=c.size(),bs;
	cin>>k;
	for(i=0;i<k;i++){
        cin>>j;
        a.push_back(j);
	}
	for(i=0;i<k;i++){
        cin>>j;
        b.push_back(j);
	}
	for(i=0;i<k;i++){
        temp.first.first=0;
        temp.first.second=0;
        temp.second=i+1;
        bs=bS(0,p,a[i]);
        if(bs!=-1){
            temp.first.first=c[bs].second;
        }
        bs=bS(0,p,b[i]);
        if(bs!=-1){
            temp.first.second=c[bs].second;
        }
        arr.push_back(temp);
        //cout<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<endl;
	}
	sort(arr.begin(),arr.end(),mycmp);
    cout<<arr[0].second<<endl;
	return 0;
}
