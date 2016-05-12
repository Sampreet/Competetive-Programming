int* primeSum(int A){
    int *arr=(int*)malloc(2*sizeof(int));
    if(A==4){
        arr[0]=2;
        arr[1]=2;
        return arr;
    }
    int prime[A+1],i,p;
    for(i=0;i<A+1;i++){
        prime[i]=1;
    }
    for(p=2; p*p<=A; p++){
        if(prime[p]==1){
            for(i=p*2;i<=A;i+=p)
                prime[i]=0;
        }
    }
    for(p=3;p<=A;p+=2){
        if(prime[p]==1 && prime[A-p]==1){
            arr[0]=prime[p];
            arr[1]=prime[A-p];
            break;
        }
    }
    if(arr[0]>arr[1]){
        int temp=arr[0];
        arr[0]=arr[1];
        arr[1]=temp;
    }
    return arr;
}
