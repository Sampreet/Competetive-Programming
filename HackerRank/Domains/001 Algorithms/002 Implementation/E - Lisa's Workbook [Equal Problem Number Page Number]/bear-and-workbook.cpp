#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,K;
    int i=1,j,in;
    int count=0;
    cin>>N>>K;
    while(N--){
        cin>>in;
        for(j=1;j<=in;j++){
            if((j-1)%K==0 && j!=1){
                i++;
            }
            if(j==i){
                count++;
            }
        }
        i++;
    }
    cout<<count;
    return 0;
}