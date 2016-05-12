#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<set<int> > a;
int suc[100006];
int en[100006];
int n;

void update(int u, int v,int i){
    en[u]=i;
    if(v!=-1){
        i=suc[v];
        u=v;
        set<int>::iterator it;
        while(i!=-1){
            for(it=a[u].begin();it!=a[u].end();++it){
                a[i].insert(*it);
            }
            a[i].insert(u);
            u=i;
            i=suc[i];
        }
    }
}

int calcEn(int v){
    set<int>::iterator it;
    int sum=0;
    for(it=a[v].begin();it!=a[v].end();++it){
        sum+=en[*it];
    }
    return sum;
}

int main(){
    int m,i,j,k,q,u,v;
    char s[105];
    set<int> se;
    set<int>::iterator it;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>en[i];
        suc[i]=-1;
        se.insert(i);
        a.push_back(se);
        se.erase(i);
    }
    for(i=0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
	    if(suc[v]==-1){
	        suc[v]=u;
	        update(u,v,en[u]);
        }
        else{
        	suc[u]=v;
        	update(v,u,en[v]);
        }
    }
    while(m--){
        cin>>s;
        if(strcmp(s,"Q")==0){
            cin>>i;
            cout<<calcEn(i-1)<<endl;
        }
        else{
            cin>>u>>i;
            u--;
            update(u,-1,i);
        }
    }
    return 0;
}
