int min(int a, int b){
    return a<b?a:b;
}

int max(int a, int b){
    return a>b?a:b;
}

int coverPoints(int* X, int n1, int* Y, int n2) {
    int i, total=0;
    int currx=X[0],curry=Y[0];
    for(i=1;i<min(n1,n2);i++){
        total+=max(abs(currx-X[i]),abs(curry-Y[i]));
        currx=X[i];
        curry=Y[i];
    }
    return total;
}
