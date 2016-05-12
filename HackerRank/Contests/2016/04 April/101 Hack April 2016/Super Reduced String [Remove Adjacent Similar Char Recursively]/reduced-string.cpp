#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    int i,j,k;
    string str;
    cin>>str;
    stack<char> a;
    a.push(str[0]);
    i=1;
    int cnt=1;
    while(str[i]){
        if(str[i]==a.top()){
            cnt++;
            if(str[i+1]=='\0' && cnt%2==0){
                a.pop();
                //cout<<"Popped "<<i<<endl;
            }
        }
        else{
            if(cnt%2==1){
                a.push(str[i]);
                //cout<<"Pushed "<<i<<endl;
                cnt=1;
            }
            else{
                a.pop();
                //cout<<"Popped "<<i<<endl;
                if(a.size()!=0 && a.top()==str[i]){
                    cnt=2;
                }
                else{
                    a.push(str[i]);
                    cnt=1;
                }
                if(str[i+1]=='\0' && a.size()!=0 && str[i]==a.top()){
                    a.pop();
                }
            }
        }
        //cout<<a.top()<<" "<<i<<endl;
        i++;
    }
    int n=a.size();
    //cout<<n<<endl;
    if(n<=0){
        cout<<"Empty String";
        return 0;
    }
    else{
    char s[n+1];
        i=0;
        s[n]='\0';
        while(a.size()!=0){
            s[n-i-1]=a.top();
            a.pop();
            i++;
        }
        cout<<s<<endl;
    }
    return 0;
}
