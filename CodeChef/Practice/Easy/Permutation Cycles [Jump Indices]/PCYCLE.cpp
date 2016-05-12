#include<iostream>
#include<vector>

using namespace std;

int main(){
    int i,j,arr[1001],k,n;
    vector<vector<int> > v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    i=0;
    while(i<n){
        if(arr[i]!=0){
            j=i;
            vector<int>temp;
            temp.push_back(j+1);
            j=arr[i]-1;
            while(arr[i]!=arr[j]){
                temp.push_back(j+1);
                k=arr[j];
                arr[j]=0;
                j=k-1;
            }
            arr[i]=0;
            temp.push_back(j+1);
            v.push_back(temp);
        }
        i++;
    }
    n=v.size();
    cout<<n;
    for(i=0;i<n;i++){
        cout<<endl;
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
    }
    return 0;
}
