#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define MAX 5001

using namespace std;

int w[MAX],h[MAX],s[MAX],cnt[MAX],path[MAX];

bool cmp(const int a, const int b){
    if(w[a]==w[b]) return h[a]>h[b];
    return w[a]>w[b];
}

int main(){
	int n,W,H,i,j,k;
	cin>>n>>W>>H;
	for(i=0;i<n;i++){
		cnt[i]=1;
		path[i]=-1;
		s[i]=i;
        cin>>w[i]>>h[i];
	}
	sort(s,s+n,cmp);
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(h[s[i]]<h[s[j]] && w[s[i]]<w[s[j]] && cnt[j]+1>cnt[i]){
				cnt[i]=cnt[j]+1;
				path[i]=j;
			}
		}
	}
	int ans=0,best=-1;
	for(i=0;i<n;i++){
		if(H<h[s[i]] && W<w[s[i]] && cnt[i]>ans){
			best=i;
			ans=cnt[i];
		}
	}
	cout<<ans<<endl;
	if(best!=-1){
		while(best!=-1){
			cout<<s[best]+1<<" ";
			best=path[best];
		}
	}
	return 0;
}
