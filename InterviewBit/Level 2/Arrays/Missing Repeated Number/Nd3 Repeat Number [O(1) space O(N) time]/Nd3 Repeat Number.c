struct eCount{
    int e;
    int c;
};

int repeatedNumber(const int* A, int n1) {
    int k=3,i,j,l;
    struct eCount temp[k-1];
    for(i=0;i<k-1;i++){
        temp[i].c=0;
    }

    for(i=0;i<n1;i++){
        for(j=0;j<k-1;j++){
            if(temp[j].e==A[i]){
                temp[j].c+=1;
                break;
            }
        }
        if(j==k-1){
            for(l=0;l<k-1;l++){
                if(temp[l].c==0){
                    temp[l].e=A[i];
                    temp[l].c=1;
                    break;
                }
            }
            if(l==k-1){
                for(l=0;l<k-1;l++){
                    temp[l].c-=1;
                }
            }
        }
    }
    for(i=0;i<k-1;i++){
        int count=0;
        for(j=0;j<n1;j++){
            if(A[j]==temp[i].e){
                count++;
            }
        }
        if(count>n1/k){
            return temp[i].e;
        }
    }
    return -1;
}
