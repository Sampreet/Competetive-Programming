#include<iostream>
#include<string>
#include<vector>

using namespace std;


string toString(int a){
    if(a==0)
        return "0";
    int i;
    string res="";
    while(a>0){
        res=string(1,'0'+a%10)+res;
        a/=10;
    }
    return res;
}

string multiply(string A, string B){
    int k1=0,k2=0;
    while(A[k1]=='0'){
        k1++;
    }
    while(B[k2]=='0'){
        k2++;
    }
    if(A[k1]=='\0' || B[k2]=='\0'){
        return "0";
    }
    A=string(A.begin()+k1,A.end());
    B=string(B.begin()+k2,B.end());
    int n1=A.size(), n2=B.size();
    int n=n1+n2;
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(0);
    }
    string res=string(n,'0');
    for(int i=0;i<n1;++i){
        for(int j=0;j<n2;++j){
            r[i+j+1]+=(A[i]-'0')*(B[j]-'0');
        }
    }
    for(int i=n-1;i>0;i--){
        if(r[i]>9)
            r[i-1]+=r[i]/10;
        res[i]+=r[i]%10;
    }
    res[0]+=r[0];
    return res[0]=='0'?string(res.begin()+1,res.end()):res;
}

string add(string a, string b){
    int i=a.length()-1,j=b.length()-1,carry=0,temp;
    string res="";
    while(i>=0 && j>=0){
        temp=a[i]-'0'+b[j]-'0'+carry;
        res=string(1,'0'+temp%10)+res;
        carry=temp/10;
        i--;
        j--;
    }
    while(j>=0){
        temp=b[j]+carry-'0';
        res=string(1,temp%10+'0')+res;
        carry=temp/10;
        j--;
    }
    while(i>=0){
        temp=a[i]+carry-'0';
        res=string(1,temp%10+'0')+res;
        carry=temp/10;
        i--;
    }
    if(carry>0){
        res=toString(carry)+res;
    }
    return res;
}

int strStr(string txt, string pat) {
    int M=pat.length();
    int N=txt.length();
    int i,j,cnt=0;

    if(M==0 || N==0){
        return 0;
    }

    int lps[M];
    int len=0;

    lps[0]=0;
    i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }

    i=0;
    j=0;
    while(i<N){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }

        if(j==M)
        {
            cnt++;
            j=lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
    return cnt;
}

int main(){
    int t,K,N,i;
    cin>>t;
    vector<string> str;
    str.push_back("0");
    str.push_back("0");
    str.push_back("1");
    for(i=3;i<22;i++){
        str.push_back(add(multiply(str[i-1],toString(i-1)),multiply(str[i-2],toString(i-2))));
    }
    while(t--){
        cin>>K>>N;
        cout<<strStr(str[N],toString(K))<<endl;
    }
    return 0;
}
