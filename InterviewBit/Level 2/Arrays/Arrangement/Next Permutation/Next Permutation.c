void nextPermutation(int* A, int n1) {
    int N=n1,i,pos,maxPos,temp;
    pos=-1;
    maxPos=-1;
    for(i=0;i<N-1;i++){
        if(A[i]<A[i+1]){
            pos=i;
        }
    }
    if(pos==-1){
        for(i=0;i<(N)/2;i++){
            temp=A[i];
            A[i]=A[N-i-1];
            A[N-i-1]=temp;
        }
        return;
    }
    for(i=pos+1;i<N;i++){
        if (A[pos]<A[i]){
            maxPos=i;
        }
    }
    temp=A[pos];
    A[pos]=A[maxPos];
    A[maxPos]=temp;
    for(i=pos+1;i<(N+pos+1)/2;i++){
        temp=A[i];
        A[i]=A[N-i+pos];
        A[N-i+pos]=temp;
    }
}
