int max(int a,int b){
    return a>b?a:b;
}

int min(int a, int b){
    return a<b?a:b;
}

int maximumGap(const int* A, int n1) {
    int *minA=(int*)malloc(n1*sizeof(int));
    int *maxA=(int*)malloc(n1*sizeof(int));
    int i,j,maxG=-1;
    minA[0]=A[0];
    maxA[n1-1]=A[n1-1];
    for(i=1;i<n1;i++){
        minA[i]=min(minA[i-1],A[i]);
        maxA[n1-1-i]=max(maxA[n1-i],A[n1-1-i]);
    }
    i=0;j=0;
    while(i<n1 && j<n1){
        if(minA[i]<=maxA[j]){
            maxG=max(maxG,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    free(minA);
    free(maxA);
    return maxG;
}
