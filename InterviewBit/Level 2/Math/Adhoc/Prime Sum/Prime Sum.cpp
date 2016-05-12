vector<int> Solution::primesum(int A) {
    vector<int> len1;
    if(A==4){
        len1.push_back(2);
        len1.push_back(2);
        return len1;
    }
    int i,p,mark1,mark2,root;
    for(p=3;p<=A;p+=2){
        mark1=1;
        mark2=1;
        root=sqrt(p);
        if(p%2==0)
            mark1=0;
        else{
            for(i=3;i<=root;i+=2){
                if(p%i==0 && p!=i)
                    mark1=0;
            }
        }
        root=sqrt(A-p);
        if((A-p)%2==0)
            mark2=0;
        else{
            for(i=3;i<=root;i+=2){
                if((A-p)%i==0 && (A-p)!=i)
                    mark2=0;
            }
        }
        if(mark1 & mark2){
            if(p>A-p){
                len1.push_back(A-p);
                len1.push_back(p);
            }
            else{
                len1.push_back(p);
                len1.push_back(A-p);
            }
            break;
        }
    }
    return len1;
}
