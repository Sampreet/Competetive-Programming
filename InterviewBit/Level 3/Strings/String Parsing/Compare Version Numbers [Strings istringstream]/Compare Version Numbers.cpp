int Solution::compareVersion(string A, string B) {
    istringstream str1(A);
    istringstream str2(B);
    string token;
    vector<string> v1;
    vector<string> v2;
    while(getline(str1,token,'.')){
        stringstream os;
        os.str(token);
        string temp;
        os>>temp;
        v1.push_back(temp);
    }
    while(getline(str2,token,'.')){
        stringstream os;
        os.str(token);
        string temp;
        os>>temp;
        v2.push_back(temp);
    }
    int n1=v1.size();
    int n2=v2.size();

    int mini=n1<n2?n1:n2;

    for(int i=0;i<mini;i++){
        int k1=v1[i].length();
        int k2=v2[i].length();
        int l1=0;
        while(v1[i][l1]=='0'){
            l1++;
        }
        k1-=l1;
        int l2=0;
        while(v2[i][l1]=='0'){
            l2++;
        }
        k2-=l2;
        if(k1>k2){
            return 1;
        }
        else if(k1<k2){
            return -1;
        }
        else{
            while(v1[i][l1] && v2[i][l2] && v1[i][l1]==v2[i][l2]){
                l1++;
                l2++;
            }
            if(v1[i][l1] && v2[i][l2]){
                if(v1[i][l1]>v2[i][l2]){
                    return 1;
                }
                if(v1[i][l1]<v2[i][l2]){
                    return -1;
                }
            }
        }
    }

    if(n1<n2){
        for(int i=n1;i<n2;i++){
            if(v2[i]!="0"){
                return -1;
            }
        }
        return 0;
    }
    if(n1>n2){
        for(int i=n2;i<n1;i++){
            if(v1[i]!="0"){
                return 1;
            }
        }
        return 0;
    }
    if(n1==n2){
        return 0;
    }
}
