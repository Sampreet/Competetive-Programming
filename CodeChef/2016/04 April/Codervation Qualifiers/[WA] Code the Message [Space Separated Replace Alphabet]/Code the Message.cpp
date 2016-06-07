#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    int i,t;
    char ch;
    string s;
    getline(cin,s);
    stringstream ss(s);
    ss>>t;
    while(t--){
        int mark=0;
        getline(cin,s);
        i=0;
        stringstream str;
        while(s[i]){
            ch=s[i];
            i++;
            if(ch<='z'&&ch>='a'){
                if(mark==1){
                    str<<"-";
                }
                else if(mark==2){
                    str<<"$";
                }
                mark=1;
                str<<((int)(ch-'a'))*((int)(ch-'a'));
            }
            else{
                if(mark!=0)
                    mark=2;
            }
        }
        cout<<str.str()<<endl;
    }
    return 0;
}
