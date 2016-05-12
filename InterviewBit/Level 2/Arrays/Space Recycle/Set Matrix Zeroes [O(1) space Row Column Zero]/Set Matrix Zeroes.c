void setZeroes(int** A, int n1, int n2) {
    int i,j,rowFlag=0,colFlag=0;

    for(i=1;i<n1;i++){
        if(A[i][0]==0){
            colFlag=1;
            A[i][0]=0;
        }
        else{
            A[i][0]=1;
        }
    }
    for(j=1;j<n2;j++){
        if(A[0][j]==0){
            rowFlag=1;
            A[0][j]=0;
        }
        else{
            A[0][j]=1;
        }
    }

    if(A[0][0]==0){
        colFlag=1;
        rowFlag=1;
    }
    A[0][0]=1;
    for(i=1;i<n1;i++){
        for(j=1;j<n2;j++){
            if(A[i][j]==0){
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }
    for(i=1;i<n1;i++){
        for(j=1;j<n2;j++){
            if(A[i][0]==0 || A[0][j]==0){
                A[i][j]=0;
            }
        }
    }
    if(colFlag==1){
        for(i=0;i<n1;i++){
            A[i][0]=0;
        }
    }
    if(rowFlag==1){
        for(i=0;i<n2;i++){
            A[0][i]=0;
        }
    }
}
